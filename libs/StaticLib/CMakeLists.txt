
# Define variables
set(LIB_NAME StaticLib)
set(LIB_SRC_DIR src)
set(LIB_INCLUDE_DIR include)

# Declare the library (and define sources)
add_library(${LIB_NAME} ${LIB_SRC_DIR}/StaticLib.cpp)

# Declare the include dir (to allow <StaticLib.hpp>)
target_include_directories(${LIB_NAME} PUBLIC
                          "${LIB_INCLUDE_DIR}"
                          )