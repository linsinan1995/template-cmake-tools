cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)

# Explicitly list the test source code and headers. The Catch header-only unit
# test framework is stored in with the test source.
set(imageEncoder_TEST_SRC
    test_encoder_init_test.cc
)
set(imageEncoder_TEST_HEADER
    catch.hpp
)

PREPEND(imageEncoder_TEST_SRC)

# Make an executable target that depends on the test source code we specified
# above.
add_executable(TestimageEncoder ${imageEncoder_TEST_SRC} ${imageEncoder_TEST_HEADER})

# Enable testing via CTest
enable_testing()
# Add our test as runnable via CTest
add_test(NAME TestimageEncoder  COMMAND TestimageEncoder)

# Link our unit tests against the library we compiled
target_link_libraries(TestimageEncoder encoderImpl)