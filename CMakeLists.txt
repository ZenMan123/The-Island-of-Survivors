# Setup cmake settings
cmake_minimum_required(VERSION 3.5)

# Setup project settings
set(PROJECT_NAME The-Island-of-Survivors)
set(CMAKE_CXX_STANDARD 20)

project(${PROJECT_NAME})

# Setup directories and wariables
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/build)

# Setup SFML
if (WIN32)
    set(SFML_DIR "libraries/SFML/windows")
endif()

find_package(SFML 2.6.0 COMPONENTS system window graphics network audio QUIET)

if(NOT SFML_FOUND)
    if (WIN32)
        message(FATAL_ERROR "SFML not found")
    elseif(APPLE)
        execute_process(COMMAND bash "-c" "brew install sfml")
        find_package(SFML 2.6.0 COMPONENTS system window graphics network audio REQUIRED)
    else()
        message(FATAL_ERROR "SFML not found, unexpected operating system")
    endif()
endif()

# Add source directories
add_subdirectory(src)
