// Fill out your copyright notice in the Description page of Project Settings.

#include "Managers/RDShareManager.h"

#if PLATFORM_ANDROID
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"
#include "Android/AndroidPlatformMisc.h"
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
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        jclass IntentClass = Env->FindClass("android/content/Intent");
        jmethodID Ctor = Env->GetMethodID(IntentClass, "<init>", "(Ljava/lang/String;)V");
        jstring ActionSend = Env->NewStringUTF("android.intent.action.SEND");
        jobject IntentObj = Env->NewObject(IntentClass, Ctor, ActionSend);

        jmethodID PutExtra = Env->GetMethodID(IntentClass, "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;");
        jstring ExtraText = Env->NewStringUTF("android.intent.extra.TEXT");
        jstring Text = Env->NewStringUTF(TCHAR_TO_UTF8(*_Text));
        Env->CallObjectMethod(IntentObj, PutExtra, ExtraText, Text);

        jmethodID SetType = Env->GetMethodID(IntentClass, "setType", "(Ljava/lang/String;)Landroid/content/Intent;");
        jstring Mime = Env->NewStringUTF("text/plain");
        Env->CallObjectMethod(IntentObj, SetType, Mime);

        jmethodID CreateChooser = Env->GetStaticMethodID(IntentClass, "createChooser", "(Landroid/content/Intent;Ljava/lang/CharSequence;)Landroid/content/Intent;");
        jstring Title = Env->NewStringUTF(TCHAR_TO_UTF8(*_ChooserTitle));
        jobject Chooser = Env->CallStaticObjectMethod(IntentClass, CreateChooser, IntentObj, Title);

        jobject Activity = FAndroidApplication::GetGameActivityThis();
        jclass ActivityClass = Env->GetObjectClass(Activity);
        jmethodID StartActivity = Env->GetMethodID(ActivityClass, "startActivity", "(Landroid/content/Intent;)V");
        Env->CallVoidMethod(Activity, StartActivity, Chooser);
    }
}

void URDShareManager::AndroidShareImage(const FString& _ImagePath, const FString& _Text)
{
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        // File + Uri via FileProvider
        jclass FileClass = Env->FindClass("java/io/File");
        jmethodID FileCtor = Env->GetMethodID(FileClass, "<init>", "(Ljava/lang/String;)V");
        jstring Path = Env->NewStringUTF(TCHAR_TO_UTF8(*_ImagePath));
        jobject FileObj = Env->NewObject(FileClass, FileCtor, Path);

        jobject Activity = FAndroidApplication::GetGameActivityThis();
        jclass ActivityClass = Env->GetObjectClass(Activity);

        jclass FileProviderClass = Env->FindClass("androidx/core/content/FileProvider");
        jmethodID GetUri = Env->GetStaticMethodID(FileProviderClass, "getUriForFile", "(Landroid/content/Context;Ljava/lang/String;Ljava/io/File;)Landroid/net/Uri;");
        FString Authority = FString::Printf(TEXT("%s.fileprovider"), *FAndroidMisc::GetPackageName());
        jstring AuthorityJ = Env->NewStringUTF(TCHAR_TO_UTF8(*Authority));
        jobject UriObj = Env->CallStaticObjectMethod(FileProviderClass, GetUri, Activity, AuthorityJ, FileObj);

        // Intent ACTION_SEND image/png
        jclass IntentClass = Env->FindClass("android/content/Intent");
        jmethodID Ctor = Env->GetMethodID(IntentClass, "<init>", "(Ljava/lang/String;)V");
        jstring ActionSend = Env->NewStringUTF("android.intent.action.SEND");
        jobject IntentObj = Env->NewObject(IntentClass, Ctor, ActionSend);

        jmethodID SetType = Env->GetMethodID(IntentClass, "setType", "(Ljava/lang/String;)Landroid/content/Intent;");
        Env->CallObjectMethod(IntentObj, SetType, Env->NewStringUTF("image/png"));

        jmethodID PutExtraStream = Env->GetMethodID(IntentClass, "putExtra", "(Ljava/lang/String;Landroid/os/Parcelable;)Landroid/content/Intent;");
        Env->CallObjectMethod(IntentObj, PutExtraStream, Env->NewStringUTF("android.intent.extra.STREAM"), UriObj);

        if (!_Text.IsEmpty())
        {
            jmethodID PutExtraText = Env->GetMethodID(IntentClass, "putExtra", "(Ljava/lang/String;Ljava/lang/String;)Landroid/content/Intent;");
            Env->CallObjectMethod(IntentObj, PutExtraText, Env->NewStringUTF("android.intent.extra.TEXT"), Env->NewStringUTF(TCHAR_TO_UTF8(*_Text)));
        }

        jmethodID AddFlags = Env->GetMethodID(IntentClass, "addFlags", "(I)Landroid/content/Intent;");
        Env->CallObjectMethod(IntentObj, AddFlags, 0x00000001); // FLAG_GRANT_READ_URI_PERMISSION

        jmethodID CreateChooser = Env->GetStaticMethodID(IntentClass, "createChooser", "(Landroid/content/Intent;Ljava/lang/CharSequence;)Landroid/content/Intent;");
        jobject Chooser = Env->CallStaticObjectMethod(IntentClass, CreateChooser, IntentObj, Env->NewStringUTF(TEXT("Partager le résultat 🎁")));

        jmethodID StartActivity = Env->GetMethodID(ActivityClass, "startActivity", "(Landroid/content/Intent;)V");
        Env->CallVoidMethod(Activity, StartActivity, Chooser);
    }
}

bool URDShareManager::AndroidScanFileInGallery(const FString& _ImagePath)
{
    if (JNIEnv* Env = FAndroidApplication::GetJavaEnv())
    {
        jclass ScannerClass = Env->FindClass("android/media/MediaScannerConnection");
        jmethodID ScanFile = Env->GetStaticMethodID(ScannerClass, "scanFile", "(Landroid/content/Context;[Ljava/lang/String;[Ljava/lang/String;Landroid/media/MediaScannerConnection$OnScanCompletedListener;)V");

        jclass StringClass = Env->FindClass("java/lang/String");
        jobjectArray Paths = Env->NewObjectArray(1, StringClass, nullptr);
        Env->SetObjectArrayElement(Paths, 0, Env->NewStringUTF(TCHAR_TO_UTF8(*_ImagePath)));

        Env->CallStaticVoidMethod(ScannerClass, ScanFile, FAndroidApplication::GetGameActivityThis(), Paths, nullptr, nullptr);
        return true;
    }
    return false;
}

#endif
