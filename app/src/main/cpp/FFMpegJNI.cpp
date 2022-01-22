#include <jni.h>

//
// Created by Joe.Lee on 2022/1/22.
//
#include <string>

extern "C"
JNIEXPORT jstring JNICALL
Java_me_hjhl_app_ffmpegturtorial_MainActivity_getFFMpegVersion(JNIEnv *env, jobject thiz) {
    std::string def("default");
    return env->NewStringUTF(def.c_str());
}