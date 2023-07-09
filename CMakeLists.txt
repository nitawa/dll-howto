cmake_minimum_required(VERSION 3.0)
project(MyDLLProject)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR})

# approach with dllimport/dllexport
add_subdirectory(A)
# approach with def
add_subdirectory(B)
# approach with global cmake flag which does everything for us
add_subdirectory(C)

# Define the executable project
add_executable(test test.cpp)
# Specify the include directories for the DLL
target_include_directories(test PUBLIC  ${CMAKE_CURRENT_SOURCE_DIR}/A ${CMAKE_CURRENT_SOURCE_DIR}/B ${CMAKE_CURRENT_SOURCE_DIR}/C)

# Link against the DLL
target_link_libraries(test PRIVATE A B C )
install(TARGETS test DESTINATION bin)
