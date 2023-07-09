cmake_minimum_required(VERSION 3.0)
project(BDLL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the DLL project
add_library(B SHARED B.cpp)
if(WIN32)
 set_target_properties(B PROPERTIES LINK_FLAGS "/DEF:${CMAKE_CURRENT_SOURCE_DIR}/B.def")
endif(WIN32)

# Specify the include directories for the DLL
target_include_directories(B PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS B DESTINATION bin)