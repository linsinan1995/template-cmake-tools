# cmake_minimum_required(VERSION 3.14)
# project(imageEncoderImpl)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/src ./*.cpp ./*.c ./*.cc)

set(impl_src
    ${SOURCES}
    )

# Form the full path to the source files...
PREPEND(impl_src)
# ... and pass the variable to the parent scope.
set(impl_src ${impl_src}  PARENT_SCOPE)

add_library(Impl ${impl_src})