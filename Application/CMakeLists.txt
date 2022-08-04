cmake_minimum_required(VERSION 3.22)

include(${CMAKE_CURRENT_SOURCE_DIR}/../Versionable/CMake/CMakeLists.txt)

project(${PROJECT_FULL_NAME})
set(RELOG relog)

include_directories("${CMAKE_CURRENT_SOURCE_DIR}")

# Logger dependency:
include_directories("/usr/local/include/Logger-1.0.0") # Access to shared library header files
link_directories("/usr/local/lib/Logger-1.0.0") # Link shared library
link_libraries(Logger-1.0.0)

# Tester dependency:
include_directories("/usr/local/include/Tester-1.0.0") # Access to shared library header files
link_directories("/usr/local/lib/Tester-1.0.0") # Link shared library
link_libraries(Tester-1.0.0)

file(GLOB APP_SRC "*.h" "*.cpp")
add_executable(${RELOG} ${APP_SRC} main.cpp)

install(TARGETS ${RELOG} DESTINATION bin/${PROJECT_NAME})