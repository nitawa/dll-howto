cmake_minimum_required(VERSION 3.0)
project(ADLL)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
# Define the DLL project
add_library(A SHARED A.cpp)

# Set the appropriate compiler flags for exporting symbols on Windows
if(WIN32)
    target_compile_definitions(A PRIVATE -DA_EXPORTS)
endif(WIN32)

# Specify the include directories for the DLL
target_include_directories(A PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
install(TARGETS A DESTINATION bin)
