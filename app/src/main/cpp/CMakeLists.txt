cmake_minimum_required(VERSION 3.18.1)


project("ffmpegturtorial")

set(CMAKE_CXX_STANDARD 17)

# 创建变量，声明了 ffmpeg 动态库的位置，将会根据 abi 有不同的区分
set(ffmpeg_lib_dir ${CMAKE_SOURCE_DIR}/../libs/${ANDROID_ABI})
# 创建变量，声明了 ffmpeg 头文件的位置
set(ffmpeg_include_dir ${CMAKE_SOURCE_DIR}/ffmpeg)

# 添加预构建的 ffmpeg 动态库到项目中
# ref：https://developer.android.com/studio/projects/configure-cmake#add-other-library
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

find_library(log-lib
        log)

target_include_directories(ffmpeg
        PRIVATE
        ${ffmpeg_include_dir}
        )

target_link_libraries(
        ffmpeg
        # 链接到 ffmpeg 动态库
        avcodec
        avdevice
        avfilter
        avformat
        swresample
        swscale
        avutil

        ${log-lib})
