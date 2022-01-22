cmake_minimum_required(VERSION 3.18.1)


project("ffmpegturtorial")

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

target_link_libraries( # Specifies the target library.
        ffmpeg

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
