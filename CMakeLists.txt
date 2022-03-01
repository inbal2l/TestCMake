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

# Set optional use of StaticLib (adds to cmake-gui and ccmake, default=ON) (3)
# will cache value per "project_build" folder 
# Option is preserved between re-builds. 
# To apply change run: cmake ../ -DUSE_STATICLIB=OFF; cmake --build .;
option(USE_STATICLIB "Use StaticLib" ON)

# Use Config.h.in to create config.h in the “poject_build” dir (the build dir) (4)
# Have to follow the options definition
configure_file(${PROJECT_SRC_DIR}/config.h.in ${PROJECT_BINARY_DIR}/config.h)

# Add StaticLib library, include folder to path (5)
if (USE_STATICLIB)
    add_subdirectory(${PROJECT_LIBS_DIR}/StaticLib)
    list(APPEND OPTIONAL_LIBS StaticLib)
    list(APPEND OPTIONAL_INCLUDES ${PROJECT_LIBS_DIR}/StaticLib)
endif()

# Project's executable (6)
add_executable(TestCMake ${PROJECT_SRC_DIR}/Main.cpp)

# Link library (7)
target_link_libraries(${PROJECT_NAME} PUBLIC ${OPTIONAL_LIBS})

# Define includes (should be after add_executable) (8)
target_include_directories(TestCMake PUBLIC
                            "${PROJECT_BINARY_DIR}"    # For using Config.h file
                            "${OPTIONAL_INCLUDES}"     # No need to specify StaticLib/include folder explicitly to use <StaticLib.hpp>
                           )

