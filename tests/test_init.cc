#define CATCH_CONFIG_MAIN

#include <opencv2/opencv.hpp>
#include "catch.hpp"

extern "C" {
#include <libavutil/avutil.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/time.h>
#include <libswresample/swresample.h>
}

#include "catch.hpp"
#include "encoder.h"

TEST_CASE("Test cmake template", "[unit-test]"){
    // not very good tests, but oh well...
    std::cout << "RUNNING TEST" << std::endl;
    REQUIRE(encode(3) == 3);
}


TEST_CASE("Test ffmepg", "[unit-test]"){
    // not very good tests, but oh well...
    avdevice_register_all();
    AVFormatContext *fmtCtx = nullptr;
    AVDictionary *options = nullptr;
    av_log_set_level( AV_LOG_DEBUG );
}
