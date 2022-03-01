
# Define variables
set(LIB_NAME HeaderLib)
set(LIB_SRC_DIR src)
set(LIB_INCLUDE_DIR include)

# Declare the library (and define sources)
add_library(${LIB_NAME} INTERFACE)

# Declare the include dir (to allow <HeaderLib.hpp>)
target_include_directories(${LIB_NAME} INTERFACE
                          "${LIB_INCLUDE_DIR}/${LIB_NAME}"
                          )