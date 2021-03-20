
file(GLOB INC_SOURCES RELATIVE ${CMAKE_SOURCE_DIR}/include ./*.hpp)

set(impl_inc
    ${INC_SOURCES}
)

# Form the full path to the source files...
PREPEND(impl_inc)
# ... and pass the variable to the parent scope.
set(impl_inc ${impl_inc}  PARENT_SCOPE)