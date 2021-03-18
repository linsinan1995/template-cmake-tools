
file(GLOB INC_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/include ./*.hpp)

set(imageEncoder_INC
    ${INC_SOURCES}
)

# Form the full path to the source files...
PREPEND(imageEncoder_INC)
# ... and pass the variable to the parent scope.
set(imageEncoder_INC ${imageEncoder_INC}  PARENT_SCOPE)