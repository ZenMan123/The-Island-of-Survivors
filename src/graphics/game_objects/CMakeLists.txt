# Merge all cpp files in library
set(TARGET_NAME textures)

add_library(${TARGET_NAME}
    game_object.cpp
    textures_manager.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    sfml-graphics
)
