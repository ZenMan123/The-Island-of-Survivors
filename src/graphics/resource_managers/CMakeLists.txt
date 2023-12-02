# Merge all cpp files in library
set(TARGET_NAME resource_managers)

add_library(${TARGET_NAME}
    textures_manager.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    sfml-graphics
)
