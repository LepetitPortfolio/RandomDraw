// Fill out your copyright notice in the Description page of Project Settings.

#include "Managers/RDShareManager.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidPlatformMisc.h"

namespace RDShareJNI
{
    // Libère automatiquement une référence locale JNI
    struct FLocalRef
    {
        JNIEnv* Env; jobject Obj;
        FLocalRef(JNIEnv* InEnv, jobject InObj) : Env(InEnv), Obj(InObj) {}
        ~FLocalRef() { if (Obj) Env->DeleteLocalRef(Obj); }
        FLocalRef(const FLocalRef&) = delete;
        FLocalRef& operator=(const FLocalRef&) = delete;
    };

    static bool CheckJNI(JNIEnv* Env, const TCHAR* What)
    {
        if (Env->ExceptionCheck())
        {
            Env->ExceptionDescribe();
            Env->ExceptionClear();
            UE_LOG(LogTemp, Error, TEXT("[RDShare] JNI exception: %s"), What);
            return false;
        }
        return true;
    }

    static jstring NewJString(JNIEnv* Env, const FString& S)
    {
        return Env->NewStringUTF(TCHAR_TO_UTF8(*S));
    }
}

#endif

void URDShareManager::ShareText(const FString& _Text, const FString& _ChooserTitle)
{
#if PLATFORM_ANDROID
    AndroidShareText(_Text, _ChooserTitle);
#else
    UE_LOG(LogTemp, Warning, TEXT("ShareText is only available on Android"));
#endif
}

void URDShareManager::ShareImage(const FString& _ImagePath, const FString& _Text)
{
#if PLATFORM_ANDROID
    AndroidShareImage(_ImagePath, _Text);
#endif
}

bool URDShareManager::ScanFileInGallery(const FString& _ImagePath)
{
#if PLATFORM_ANDROID
    return AndroidScanFileInGallery(_ImagePath);
#endif
    return false;
}

#if PLATFORM_ANDROID

void URDShareManager::AndroidShareText(const FString& _Text, const FString& _ChooserTitle)
{
    using namespace RDShareJNI;
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();
    if (!Env) return;

    jclass IntentClass = Env->FindClass("android/content/Intent");
    if (!CheckJNI(Env, TEXT("FindClass Intent")) || !IntentClass) return;
    FLocalRef IntentClassRef(Env, IntentClass);

    jmethodID Ctor = Env->GetMethodID(IntentClass, "<init>", "(Ljava/lang/String;)V");
    jmethodID PutExtra = Env->GetMethodID(IntentClass, "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;");
    jmethodID SetType = Env->GetMethodID(IntentClass, "setType", "(Ljava/lang/String;)Landroid/content/Intent;");
    jmethodID CreateChooser = Env->GetStaticMethodID(IntentClass, "createChooser", "(Landroid/content/Intent;Ljava/lang/CharSequence;)Landroid/content/Intent;");
    if (!CheckJNI(Env, TEXT("GetMethodID Intent")) || !Ctor || !PutExtra || !SetType || !CreateChooser) return;

    FLocalRef ActionSend(Env, NewJString(Env, TEXT("android.intent.action.SEND")));
    FLocalRef IntentObj(Env, Env->NewObject(IntentClass, Ctor, (jstring)ActionSend.Obj));
    if (!CheckJNI(Env, TEXT("new Intent")) || !IntentObj.Obj) return;

    FLocalRef ExtraTextKey(Env, NewJString(Env, TEXT("android.intent.extra.TEXT")));
    FLocalRef TextJ(Env, NewJString(Env, _Text));
    FLocalRef R1(Env, Env->CallObjectMethod(IntentObj.Obj, PutExtra, (jstring)ExtraTextKey.Obj, (jstring)TextJ.Obj));

    FLocalRef Mime(Env, NewJString(Env, TEXT("text/plain")));
    FLocalRef R2(Env, Env->CallObjectMethod(IntentObj.Obj, SetType, (jstring)Mime.Obj));

    FLocalRef TitleJ(Env, NewJString(Env, _ChooserTitle));
    FLocalRef Chooser(Env, Env->CallStaticObjectMethod(IntentClass, CreateChooser, IntentObj.Obj, (jstring)TitleJ.Obj));
    if (!CheckJNI(Env, TEXT("createChooser")) || !Chooser.Obj) return;

    jobject Activity = FAndroidApplication::GetGameActivityThis();
    FLocalRef ActivityClass(Env, Env->GetObjectClass(Activity));
    jmethodID StartActivity = Env->GetMethodID((jclass)ActivityClass.Obj, "startActivity", "(Landroid/content/Intent;)V");
    if (!CheckJNI(Env, TEXT("GetMethodID startActivity")) || !StartActivity) return;

    Env->CallVoidMethod(Activity, StartActivity, Chooser.Obj);
    CheckJNI(Env, TEXT("startActivity"));
}

void URDShareManager::AndroidShareImage(const FString& _ImagePath, const FString& _Text)
{
    using namespace RDShareJNI;

    if (!FPaths::FileExists(_ImagePath))
    {
        UE_LOG(LogTemp, Error, TEXT("[RDShare] Fichier inexistant: %s"), *_ImagePath);
        return;
    }

    JNIEnv* Env = FAndroidApplication::GetJavaEnv();
    if (!Env) return;

    jobject Activity = FAndroidApplication::GetGameActivityThis();
    FLocalRef ActivityClass(Env, Env->GetObjectClass(Activity));

    // --- File ---
    jclass FileClass = Env->FindClass("java/io/File");
    if (!CheckJNI(Env, TEXT("FindClass File")) || !FileClass) return;
    FLocalRef FileClassRef(Env, FileClass);
    jmethodID FileCtor = Env->GetMethodID(FileClass, "<init>", "(Ljava/lang/String;)V");
    FLocalRef PathJ(Env, NewJString(Env, _ImagePath));
    FLocalRef FileObj(Env, Env->NewObject(FileClass, FileCtor, (jstring)PathJ.Obj));
    if (!CheckJNI(Env, TEXT("new File")) || !FileObj.Obj) return;

    // --- Authority : packageName + ".fileprovider" ---
    jmethodID GetPackageName = Env->GetMethodID((jclass)ActivityClass.Obj, "getPackageName", "()Ljava/lang/String;");
    FLocalRef PkgJ(Env, Env->CallObjectMethod(Activity, GetPackageName));
    if (!CheckJNI(Env, TEXT("getPackageName")) || !PkgJ.Obj) return;
    const char* PkgChars = Env->GetStringUTFChars((jstring)PkgJ.Obj, nullptr);
    FString Authority = FString::Printf(TEXT("%s.fileprovider"), UTF8_TO_TCHAR(PkgChars));
    Env->ReleaseStringUTFChars((jstring)PkgJ.Obj, PkgChars);

    // --- Uri via FileProvider ---
    jclass FileProviderClass = Env->FindClass("androidx/core/content/FileProvider");
    if (!CheckJNI(Env, TEXT("FindClass FileProvider")) || !FileProviderClass) return;
    FLocalRef FPRef(Env, FileProviderClass);
    jmethodID GetUri = Env->GetStaticMethodID(FileProviderClass, "getUriForFile",
        "(Landroid/content/Context;Ljava/lang/String;Ljava/io/File;)Landroid/net/Uri;");
    if (!CheckJNI(Env, TEXT("GetStaticMethodID getUriForFile")) || !GetUri) return;

    FLocalRef AuthorityJ(Env, NewJString(Env, Authority));
    FLocalRef UriObj(Env, Env->CallStaticObjectMethod(FileProviderClass, GetUri, Activity, (jstring)AuthorityJ.Obj, FileObj.Obj));
    if (!CheckJNI(Env, TEXT("getUriForFile")) || !UriObj.Obj)
    {
        UE_LOG(LogTemp, Error, TEXT("[RDShare] getUriForFile a échoué pour: %s (authority=%s)"), *_ImagePath, *Authority);
        return;
    }

    // --- Intent ---
    jclass IntentClass = Env->FindClass("android/content/Intent");
    if (!CheckJNI(Env, TEXT("FindClass Intent")) || !IntentClass) return;
    FLocalRef IntentClassRef(Env, IntentClass);

    jmethodID Ctor = Env->GetMethodID(IntentClass, "<init>", "(Ljava/lang/String;)V");
    jmethodID SetType = Env->GetMethodID(IntentClass, "setType", "(Ljava/lang/String;)Landroid/content/Intent;");
    jmethodID PutExtraParcel = Env->GetMethodID(IntentClass, "putExtra", "(Ljava/lang/String;Landroid/os/Parcelable;)Landroid/content/Intent;");
    jmethodID PutExtraStr = Env->GetMethodID(IntentClass, "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;");
    jmethodID AddFlags = Env->GetMethodID(IntentClass, "addFlags", "(I)Landroid/content/Intent;");
    jmethodID CreateChooser = Env->GetStaticMethodID(IntentClass, "createChooser", "(Landroid/content/Intent;Ljava/lang/CharSequence;)Landroid/content/Intent;");
    if (!CheckJNI(Env, TEXT("GetMethodID Intent")) || !Ctor || !SetType || !PutExtraParcel || !PutExtraStr || !AddFlags || !CreateChooser) return;

    FLocalRef ActionJ(Env, NewJString(Env, TEXT("android.intent.action.SEND")));
    FLocalRef IntentObj(Env, Env->NewObject(IntentClass, Ctor, (jstring)ActionJ.Obj));
    if (!CheckJNI(Env, TEXT("new Intent")) || !IntentObj.Obj) return;

    FLocalRef MimeJ(Env, NewJString(Env, TEXT("image/png")));
    FLocalRef R1(Env, Env->CallObjectMethod(IntentObj.Obj, SetType, (jstring)MimeJ.Obj));

    FLocalRef StreamKey(Env, NewJString(Env, TEXT("android.intent.extra.STREAM")));
    FLocalRef R2(Env, Env->CallObjectMethod(IntentObj.Obj, PutExtraParcel, (jstring)StreamKey.Obj, UriObj.Obj));

    if (!_Text.IsEmpty())
    {
        FLocalRef TextKey(Env, NewJString(Env, TEXT("android.intent.extra.TEXT")));
        FLocalRef TextJ(Env, NewJString(Env, _Text));
        FLocalRef R3(Env, Env->CallObjectMethod(IntentObj.Obj, PutExtraStr, (jstring)TextKey.Obj, (jstring)TextJ.Obj));
    }

    // ClipData : permissions de lecture plus fiables sur Android récent
    jclass ClipDataClass = Env->FindClass("android/content/ClipData");
    if (CheckJNI(Env, TEXT("FindClass ClipData")) && ClipDataClass)
    {
        FLocalRef ClipClassRef(Env, ClipDataClass);
        jmethodID NewRawUri = Env->GetStaticMethodID(ClipDataClass, "newRawUri",
            "(Ljava/lang/CharSequence;Landroid/net/Uri;)Landroid/content/ClipData;");
        jmethodID SetClipData = Env->GetMethodID(IntentClass, "setClipData", "(Landroid/content/ClipData;)V");
        if (CheckJNI(Env, TEXT("ClipData methods")) && NewRawUri && SetClipData)
        {
            FLocalRef LabelJ(Env, NewJString(Env, TEXT("image")));
            FLocalRef Clip(Env, Env->CallStaticObjectMethod(ClipDataClass, NewRawUri, (jstring)LabelJ.Obj, UriObj.Obj));
            if (CheckJNI(Env, TEXT("newRawUri")) && Clip.Obj)
            {
                Env->CallVoidMethod(IntentObj.Obj, SetClipData, Clip.Obj);
                CheckJNI(Env, TEXT("setClipData"));
            }
        }
    }

    FLocalRef R4(Env, Env->CallObjectMethod(IntentObj.Obj, AddFlags, 0x00000001)); // FLAG_GRANT_READ_URI_PERMISSION

    FLocalRef TitleJ(Env, NewJString(Env, TEXT("Partager le résultat")));
    FLocalRef Chooser(Env, Env->CallStaticObjectMethod(IntentClass, CreateChooser, IntentObj.Obj, (jstring)TitleJ.Obj));
    if (!CheckJNI(Env, TEXT("createChooser")) || !Chooser.Obj) return;
    FLocalRef R5(Env, Env->CallObjectMethod(Chooser.Obj, AddFlags, 0x00000001));

    jmethodID StartActivity = Env->GetMethodID((jclass)ActivityClass.Obj, "startActivity", "(Landroid/content/Intent;)V");
    if (!CheckJNI(Env, TEXT("GetMethodID startActivity")) || !StartActivity) return;

    Env->CallVoidMethod(Activity, StartActivity, Chooser.Obj);
    CheckJNI(Env, TEXT("startActivity"));
}

bool URDShareManager::AndroidScanFileInGallery(const FString& _ImagePath)
{
    using namespace RDShareJNI;
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();
    if (!Env) return false;

    jobject Activity = FAndroidApplication::GetGameActivityThis();
    FLocalRef ActivityClass(Env, Env->GetObjectClass(Activity));
    jmethodID Method = Env->GetMethodID((jclass)ActivityClass.Obj, "rdSaveImageToGallery", "(Ljava/lang/String;Ljava/lang/String;)Z");
    if (!CheckJNI(Env, TEXT("GetMethodID rdSaveImageToGallery")) || !Method) return false;

    FLocalRef PathJ(Env, NewJString(Env, _ImagePath));
    FLocalRef NameJ(Env, NewJString(Env, FPaths::GetCleanFilename(_ImagePath)));
    jboolean Ok = Env->CallBooleanMethod(Activity, Method, (jstring)PathJ.Obj, (jstring)NameJ.Obj);
    return CheckJNI(Env, TEXT("rdSaveImageToGallery")) && Ok;
}
#endif