cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(Tryout)

# The version number.
set(LOGGER_VERSION_MAJOR 1)
set(LOGGER_VERSION_MINOR 0)

include_directories("${PROJECT_BINARY_DIR}" "${PROJECT_BINARY_DIR}/Tests" "${PROJECT_BINARY_DIR}/Tests/Implementations")

set(EXTRA_LIBS ${EXTRA_LIBS})

file(
        GLOB APP_TEST_SRC
        "Tests/*.h"
        "Tests/*.cpp"
        "Tests/Implementations/*.h"
        "Tests/Implementations/*.cpp"
)

file(GLOB APP_SRC)

# Logger dependency:
include_directories("/usr/local/include/Logger") # Access to shared library header files
link_directories("/usr/local/lib/Logger") # Link shared library
link_libraries(Logger)

# Tester dependency:
include_directories("/usr/local/include/Tester") # Access to shared library header files
link_directories("/usr/local/lib/Tester") # Link shared library
link_libraries(Tester)

add_executable(Tryout ${APP_SRC} main.cpp)
add_executable(Test ${APP_SRC} ${APP_TEST_SRC} tests.cpp)
add_executable(MocksGenerator ${APP_SRC} ${APP_TEST_SRC} mock_log_data_generator.cpp)

set(DO_TEST true)

if (${DO_TEST})
    add_custom_command(TARGET MocksGenerator
            POST_BUILD
            COMMAND ./MocksGenerator && ./Test
            )
endif (${DO_TEST})
