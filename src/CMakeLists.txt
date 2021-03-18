# cmake_minimum_required(VERSION 3.14)
# project(imageEncoderImpl)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/src ./*.cpp ./*.c ./*.cc)

set(imageEncoder_SRC
    ${SOURCES}
    )

# Form the full path to the source files...
PREPEND(imageEncoder_SRC)
# ... and pass the variable to the parent scope.
set(imageEncoder_SRC ${imageEncoder_SRC}  PARENT_SCOPE)

add_library(encoderImpl ${imageEncoder_SRC})