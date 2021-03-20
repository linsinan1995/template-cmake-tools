cmake_minimum_required(VERSION 3.14)
project(gst-rtp-server VERSION 0.1)
set(gst_rtp_VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)

# enable unit testing via "make test" once the code has been compiled.
include(CTest)

# set debug or release mode for compilation
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING
      "Choose the type of build, options are: Debug Release."
      FORCE)
endif(NOT CMAKE_BUILD_TYPE)

if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "GCC")
        set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -g")
        set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")
endif()

# add dependencies (system installation)
find_package(PkgConfig)
pkg_check_modules(GST REQUIRED gstreamer-1.0>=1.15)
pkg_check_modules(OpenCV REQUIRED opencv>=4.4)
pkg_check_modules(ffmpeg REQUIRED libavcodec>=55.0.0 libavutil>=56.0.0 libswresample>=3.0.0)
pkg_check_modules(LIBAV REQUIRED IMPORTED_TARGET
    libavdevice
    libavfilter
    libavformat
    libavcodec
    libswresample
    libswscale
    libavutil
)

include_directories(${GST_INCLUDE_DIRS})
link_libraries(${GST_LIBRARIES})

include_directories(${OpenCV_INCLUDE_DIRS})
link_libraries(${OpenCV_LIBS})

link_libraries(PkgConfig::LIBAV)

# Function to prepend the subdirectory to source files in subdirectories
FUNCTION(PREPEND var )
   SET(listVar "")
   FOREACH(f ${${var}})
       LIST(APPEND listVar "${CMAKE_CURRENT_SOURCE_DIR}/${f}")
   ENDFOREACH(f)
   SET(${var} "${listVar}" PARENT_SCOPE)
ENDFUNCTION(PREPEND)

include_directories(include)
add_subdirectory(include)
add_subdirectory(src)

if (BUILD_TESTING)
    message("Build with Testing")
    add_subdirectory(tests)
endif()

add_executable(${PROJECT_NAME} main.cc ${impl_src} ${impl_inc})

target_link_libraries(
    ${PROJECT_NAME}
    Impl
)