cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

# Explicitly list the test source code and headers. The Catch header-only unit
# test framework is stored in with the test source.
set(TEST_SRC
    test_init.cc
)
set(TEST_HEADER
    catch.hpp
)

PREPEND(TEST_SRC)

# Make an executable target that depends on the test source code we specified
# above.
add_executable(impl_test ${TEST_SRC} ${TEST_HEADER})

# Enable testing via CTest
enable_testing()
# Add our test as runnable via CTest
add_test(NAME impl_test  COMMAND impl_test)

# Link our unit tests against the library we compiled
target_link_libraries(impl_test Impl)