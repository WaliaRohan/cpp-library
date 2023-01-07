project(bin_tree_tests)

cmake_minimum_required(VERSION 3.0)

# Include source directory and add cpp files
include_directories(../)
file(GLOB SOURCE "../*.h")
file(GLOB SOURCES "../*.cpp")

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(test_node test_node.cpp)
target_link_libraries(test_node ${GTEST_LIBRARIES} pthread)

add_executable(test_bin_tree test_bin_tree.cpp ${SOURCES})