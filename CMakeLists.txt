cmake_minimum_required(VERSION 3.10)
project (determinant-calculator VERSION 1.0.0 LANGUAGES CXX )

# Enable compile commands
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_BUILD_TYPE Debug)

#=== SETTING VARIABLES ===#
set(APP_NAME "determinant-calculator")
set(INCLUDE_DIR "include")
set(COMPILE_OPTIONS ${CMAKE_CXX_FLAGS} "-Wall" "-pedantic" "-g3")

# Set sources
file(GLOB SOURCES "src/*.cpp")

# Remove main from sources
list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/core/main.cpp")
list(REMOVE_ITEM TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/test/main.cpp")

# Include directories
include_directories(${INCLUDE_DIR})

# Set compiler flags
add_compile_options(${COMPILE_OPTIONS})

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#=== Main App ===

# Create library
add_library(DetLib ${SOURCES})

# Create executable
add_executable(${APP_NAME} src/main.cpp)

# Link executable with library
target_link_libraries(${APP_NAME} DetLib)
