# Setup cmake settings
cmake_minimum_required(VERSION 3.2)

# Setup project settings
project(The-Island-of-Survivors)
set(CMAKE_CXX_STANDARD 20)

# Setup directories
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

# Add all source files
file(GLOB CPP_SOURCE_FILES src/*.cpp)
foreach(SOURCE_PATH ${CPP_SOURCE_FILES})
    get_filename_component(EXECUTABLE_NAME ${SOURCE_PATH} NAME_WE)

    add_executable(${EXECUTABLE_NAME} ${SOURCE_PATH})

    target_link_libraries(${EXECUTABLE_NAME} sfml-graphics)

    # Copy SFML DLL files to the target folder
    foreach(DLL_PACKAGE ${SFML_DLL_PACKAGES})
        add_custom_command(TARGET ${EXECUTABLE_NAME} POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different
                ${SFML_DLL_PACKAGES_PATH}/${DLL_PACKAGE}
                $<TARGET_FILE_DIR:${EXECUTABLE_NAME}>)
    endforeach(DLL_PACKAGE ${SFML_DLL_PACKAGES})
endforeach(SOURCE_PATH ${CPP_SOURCE_FILES})
