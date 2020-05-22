cmake_minimum_required(VERSION 3.13)
project(PriorityList)

set(CMAKE_CXX_STANDARD 14)

# Change this path to wherever you have the file 'catch.hpp'
include_directories(/Users/jjpal/CLionProjects/)

# Using this add_execuatable with the two line file
# catch-main.cpp to prevent catch.hpp compiling
# with any change made to LinkedPriorityListTest.cpp
add_executable(PriorityList
               catch-main.cpp
        LinkedPriorityListTest.cpp
        LinkedPriorityList.cpp
        )
