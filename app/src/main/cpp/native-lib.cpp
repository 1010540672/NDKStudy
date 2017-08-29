#include <jni.h>
#include <string>
#include<android/log.h>
#define LOG_TAG "JNI_STUDY"
#define LOGI(fmt, args...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, fmt, ##args)
#define LOGD(fmt, args...) __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, fmt, ##args)
#define LOGE(fmt, args...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, fmt, ##args)




#ifdef __cplusplus
extern "C" {
#endif
 jstring
Java_com_yqq_ndkstudy_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

 void
Java_com_yqq_ndkstudy_MainActivity_enCrypt(JNIEnv *env, jobject instance, jstring src_,
                                           jstring dst_) {
    const   char *src = env->GetStringUTFChars(src_, 0);
    const char *dst = env->GetStringUTFChars(dst_, 0);

    LOGE("%s\n src=", src);
    // TODO
   // dst=src;

    env->ReleaseStringUTFChars(src_, src);
    env->ReleaseStringUTFChars(dst_, dst);
}

 void
Java_com_yqq_ndkstudy_MainActivity_deCrypt(JNIEnv *env, jobject instance, jstring src_,
                                           jstring dst_) {
    const char *src = env->GetStringUTFChars(src_, 0);
    const char *dst = env->GetStringUTFChars(dst_, 0);
     LOGE("%s\n src=", src);
    // TODO

    env->ReleaseStringUTFChars(src_, src);
    env->ReleaseStringUTFChars(dst_, dst);
}

jstring
Java_com_yqq_ndkstudy_MainActivity_getResult(JNIEnv *env, jobject instance, jstring params_) {

    const char *params = env->GetStringUTFChars(params_,0);

    if(NULL==params){
        LOGE("%s\n test=", "OOM ");
        return NULL;

    }
    LOGE("%s\n params=", params);
    const  char *test= "=====JNI字符串返回===";
    LOGE("%s\n test=", test);
    // TODO
   // return env->NewStringUTF(hello.c_str());
    env->ReleaseStringUTFChars(params_, params);


    return env->NewStringUTF(test);
}

 jint
Java_com_yqq_ndkstudy_MainActivity_getIntResult(JNIEnv *env, jobject instance, jint a, jint b) {
     LOGE("%d\n a=", a);
     LOGE("%d\n b=", b);
     LOGE("%s\n a+b=","整型数据传递");
     return a+b;
}


static jclass clazz1;
jobject
Java_com_yqq_ndkstudy_MainActivity_getObjectTest(JNIEnv *env, jobject instance, jobject params) {

    // TODO
    //H:\github\study\NDKStudy\app\src\main\java\com\yqq\ndkstudy\User.java


    jclass  myClass=env->FindClass("com/yqq/ndkstudy/User");
      clazz1 = (jclass)env->NewGlobalRef(myClass);
   jobject jobj=env->AllocObject(clazz1);
   // jclass jobj = (jclass) env->NewGlobalRef(jobj2);
//    jclass clazz=env->GetObjectClass(params);
//    jobject obj=env->GetObjectClass(clazz1);
    jmethodID methodId= env->GetMethodID(clazz1,"getmName","()Ljava/lang/String;");
    LOGE("%s\n 对象传递=methodId",methodId);

    jstring  js_name=(jstring)env->CallObjectMethod(jobj,methodId,NULL);
    LOGE("%s\n 对象传递=",js_name);

    jmethodID methodId2= env->GetMethodID(clazz1,"setmName","(Ljava/lang/String;)V");
   // env->CallObjectMethod(jobj,methodId2,"测试了");
    env->CallVoidMethod(jobj,methodId2,"测试了");
    return jobj;
   //env->SetObjectField(clazz,"mAge","对象的年龄---19");


//    jclass  clazz=env->FindClass("com/yqq/ndkstudy/User");
//
//    if(clazz==0){
//        return 0;
//    }
//
//    jobject  obj=env->AllocObject(clazz);
//    env->SetObjectField(clazz,"mName","测试对象属性修改name");
//    env->SetObjectField(clazz,"mAge","对象的年龄---19");
//    return obj;

}



#ifdef __cplusplus
}
#endif