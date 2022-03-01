# @@@ Define CMake parameters (1) @@@
cmake_minimum_required(VERSION 3.10)

# Define variables
set(PROJECT_SRC_DIR src)
set(PROJECT_LIBS_DIR libs)
set(PROJECT_NAME TestCMake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# @@@ Define project info (2) @@@ 
project(${PROJECT_NAME} VERSION 1.0.0)

# Use Config.h.in to create config.h in the “poject_build” dir (the build dir) (3)
configure_file(${PROJECT_SRC_DIR}/config.h.in ${PROJECT_BINARY_DIR}/config.h)

# Add library (4)
add_subdirectory(${PROJECT_LIBS_DIR}/StaticLib)

# Project's executable (5)
add_executable(TestCMake ${PROJECT_SRC_DIR}/Main.cpp)

# Link library (6)
target_link_libraries(${PROJECT_NAME} PUBLIC StaticLib)

# Define includes (should be after add_executable) (7)
target_include_directories(TestCMake PUBLIC
                            "${PROJECT_BINARY_DIR}"             # For using Config.h file
                            "${PROJECT_LIBS_DIR}/StaticLib"     # No need to specify StaticLib/include explicitly to use <StaticLib.hpp>
                           )

