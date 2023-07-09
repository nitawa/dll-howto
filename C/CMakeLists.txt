cmake_minimum_required(VERSION 3.0)
project(CDLL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Define the DLL project
add_library(C SHARED C.cpp)
if(WIN32)
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
  
  add_library(C_lib STATIC  C.cpp)
  TARGET_LINK_LIBRARIES(C_lib ${_link_LIBRARIES})
  set_target_properties(C_lib PROPERTIES OUTPUT_NAME C)
endif(WIN32)

# Specify the include directories for the DLL
target_include_directories(C PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS C DESTINATION bin)
