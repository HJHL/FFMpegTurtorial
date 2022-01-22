#include <jni.h>

//
// Created by Joe.Lee on 2022/1/22.
//
#include <string>

// 尤其注意这里，ffmpeg 是 c 库，在 include 它的头文件时，也必须以 c 的方式引入，
// 否则链接时会出现异常，提示找不到符号。
extern "C" {
#include "libavcodec/version.h"
#include "libavcodec/avcodec.h"
#include "libavfilter/version.h"
#include "libavformat/version.h"
#include "libswscale/version.h"
#include "libswresample/version.h"
}

extern "C"
JNIEXPORT jstring JNICALL
Java_me_hjhl_app_ffmpegturtorial_MainActivity_getFFMpegVersion(JNIEnv *env, jobject thiz) {
    std::string def;

    def.append("libavcodec: " AV_STRINGIFY(LIBAVCODEC_VERSION) "\n");
    def.append("libavfilter: " AV_STRINGIFY(LIBAVFILTER_VERSION) "\n");
    def.append("libavformat: " AV_STRINGIFY(LIBAVFORMAT_VERSION) "\n");
    def.append("libavutil: " AV_STRINGIFY(LIBAVUTIL_VERSION) "\n");
    def.append("libswscale: " AV_STRINGIFY(LIBSWSCALE_VERSION) "\n");
    def.append("libswresample: " AV_STRINGIFY(LIBSWRESAMPLE_VERSION) "\n");
    def.append("avcodec license: ");
    def.append(avcodec_license());
    def.append("\n");
    def.append("build command: ./configure ");
    def.append(avcodec_configuration());

    return env->NewStringUTF(def.c_str());
}