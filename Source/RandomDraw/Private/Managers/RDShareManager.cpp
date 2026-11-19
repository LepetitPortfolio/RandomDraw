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
    JNIEnv* Env = FAndroidApplication::GetJavaEnv();
    if (!Env) return;

    jobject Activity = FAndroidApplication::GetGameActivityThis();
    FLocalRef ActivityClass(Env, Env->GetObjectClass(Activity));
    if (!CheckJNI(Env, TEXT("GetObjectClass activity")) || !ActivityClass.Obj) return;

    jmethodID Method = Env->GetMethodID((jclass)ActivityClass.Obj,
        "rdShareImage", "(Ljava/lang/String;Ljava/lang/String;)Z");
    if (!CheckJNI(Env, TEXT("GetMethodID rdShareImage")) || !Method) return;

    FLocalRef ImagePathJ(Env, NewJString(Env, _ImagePath));
    FLocalRef TextJ(Env, NewJString(Env, _Text));
    if (!ImagePathJ.Obj || !TextJ.Obj) return;

    jboolean Ok = Env->CallBooleanMethod(Activity, Method,
        (jstring)ImagePathJ.Obj, (jstring)TextJ.Obj);
    CheckJNI(Env, TEXT("rdShareImage"));
    if (!Ok) UE_LOG(LogTemp, Warning, TEXT("rdShareImage a retourné false"));
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