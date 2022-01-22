cmake_minimum_required(VERSION 3.18.1)


project("ffmpegturtorial")

set(CMAKE_CXX_STANDARD 17)

set(ffmpeg_lib_dir ${CMAKE_SOURCE_DIR}/../libs/${ANDROID_ABI})
set(ffmpeg_include_dir ${CMAKE_SOURCE_DIR}/ffmpeg)

add_library(avcodec SHARED IMPORTED)
set_target_properties(avcodec
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavcodec.so)

add_library(avdevice SHARED IMPORTED)
set_target_properties(avdevice
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavdevice.so)

add_library(avfilter SHARED IMPORTED)
set_target_properties(avfilter
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavfilter.so)

add_library(avformat SHARED IMPORTED)
set_target_properties(avformat
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavformat.so)

add_library(swresample SHARED IMPORTED)
set_target_properties(swresample
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libswresample.so)

add_library(swscale SHARED IMPORTED)
set_target_properties(swscale
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libswscale.so)

add_library(avutil SHARED IMPORTED)
set_target_properties(avutil
        PROPERTIES IMPORTED_LOCATION
        ${ffmpeg_lib_dir}/libavutil.so)

add_library(ffmpeg
        SHARED
        FFMpegJNI.cpp)

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_include_directories(ffmpeg
        PRIVATE
        ${ffmpeg_include_dir}
        )

target_link_libraries( # Specifies the target library.
        ffmpeg

        avcodec
        avdevice
        avfilter
        avformat
        swresample
        swscale
        avutil

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
