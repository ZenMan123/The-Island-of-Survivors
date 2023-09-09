# Add source directories
add_subdirectory(common)

# Create exeutable target
add_executable(${PROJECT_NAME} main.cpp)

# Add link libraries
target_link_libraries(${PROJECT_NAME}
    common
    sfml-graphics
)

# Add dynamic SFML lilbraries
foreach(DLL_PACKAGE ${SFML_DLL_PACKAGES})
add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy_if_different 
        ${SFML_DLL_PACKAGES_PATH}/${DLL_PACKAGE}
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
endforeach(DLL_PACKAGE ${SFML_DLL_PACKAGES})
