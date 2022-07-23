cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(Logger)

# The version number.
set(LOGGER_VERSION_MAJOR 1)
set(LOGGER_VERSION_MINOR 0)

# Configure a header file to pass some of the CMake settings  to the source code
configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/LoggerConfig.h.in"
        "${CMAKE_CURRENT_SOURCE_DIR}/LoggerConfig.h"
)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")
include_directories("Implementations")

file(GLOB LIB_SRC "*.h" "*.cpp" "Implementations/*.h" "Implementations/*.cpp")
add_library(Logger ${LIB_SRC})

# Install library
install(TARGETS ${PROJECT_NAME} DESTINATION lib/${PROJECT_NAME})

# Install library headers
file(GLOB HEADERS *.h Implementations/*.h)
install(FILES ${HEADERS} DESTINATION include/${PROJECT_NAME})