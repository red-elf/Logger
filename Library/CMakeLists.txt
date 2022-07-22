cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(Logger)

# The version number.
set(LOGGER_VERSION_MAJOR 0)
set(LOGGER_VERSION_MINOR 1)

# Configure a header file to pass some of the CMake settings  to the source code
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/LoggerConfig.h.in"
        "${CMAKE_CURRENT_SOURCE_DIR}/LoggerConfig.h"
)

include_directories("Implementations")

file(GLOB LIB_SRC "*.h" "*.cpp")
add_library(LoggingSystemLibrary ${LIB_SRC})

# TODO:
# Build a CPack driven installer package
#include (InstallRequiredSystemLibraries)
#set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#set (CPACK_PACKAGE_VERSION_MAJOR "${LoggingSystemLibrary_VERSION_MAJOR}")
#set (CPACK_PACKAGE_VERSION_MINOR "${LoggingSystemLibrary_VERSION_MINOR}")
#include (CPack)