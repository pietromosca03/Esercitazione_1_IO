cmake_minimum_required(VERSION 3.9)

project(MeanValue LANGUAGES CXX C VERSION 1.0.0)

# Set C++ Standard
################################################################################
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# IMPOSE WARNINGS ON DEBUG
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Wextra -pedantic-errors")

# IMPOSE CXX FLAGS FOR WINDOWS
if (WIN32)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
endif (WIN32)

# Add dependencies
################################################################################

## Eigen3
find_package(Eigen3 CONFIG REQUIRED)
list(APPEND MeanValue_LINKED_LIBRARIES PUBLIC Eigen3::Eigen)

## Threads
find_package(Threads REQUIRED)
list(APPEND MeanValue_LINKED_LIBRARIES PRIVATE Threads::Threads)

## GTest
find_package(GTest REQUIRED)

list(APPEND MeanValue_LINKED_LIBRARIES PRIVATE GTest::gtest)
list(APPEND MeanValue_LINKED_LIBRARIES PRIVATE GTest::gtest_main)
list(APPEND MeanValue_LINKED_LIBRARIES PRIVATE GTest::gmock)
list(APPEND MeanValue_LINKED_LIBRARIES PRIVATE GTest::gmock_main)

# Create executable
################################################################################
add_executable(${Exercise2}
    main.cpp
    ${MeanValue_SOURCES}
    ${MeanValue_HEADERS})

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/data.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

target_link_libraries(${Exercise2} ${MeanValue_LINKED_LIBRARIES})
target_include_directories(${Exercise2} PRIVATE ${MeanValue_INCLUDE})
target_compile_options(${Exercise2} PUBLIC -fPIC)
