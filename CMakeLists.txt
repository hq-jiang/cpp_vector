project(vector)
cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(sources main.cpp vector.h)
add_executable(${PROJECT_NAME} ${sources})

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
set(TEST_NAME tests)
add_executable(${TEST_NAME} test_vector.cpp)
target_link_libraries(${TEST_NAME} ${GTEST_LIBRARIES} pthread)

add_custom_target(RUN_${TEST_NAME} ALL
                  COMMAND "${TEST_NAME}"
                  COMMENT "Running ${TEST_NAME}...")