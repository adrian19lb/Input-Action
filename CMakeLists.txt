cmake_minimum_required(VERSION 3.0.0)
project(Input-Action)

#Add unit tests to build
option(PACKAGE_TESTS "Build the tests" ON)
if (PACKAGE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
