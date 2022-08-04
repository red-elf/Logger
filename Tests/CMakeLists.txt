cmake_minimum_required(VERSION 3.22)

set(CMAKE_CXX_STANDARD 17)

project(Tryout)

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
include_directories("/usr/local/include/Logger-1.0.0") # Access to shared library header files
link_directories("/usr/local/lib/Logger-1.0.0") # Link shared library
link_libraries(Logger-1.0.0)

# Tester dependency:
include_directories("/usr/local/include/Tester-1.0.0") # Access to shared library header files
link_directories("/usr/local/lib/Tester-1.0.0") # Link shared library
link_libraries(Tester-1.0.0)

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
