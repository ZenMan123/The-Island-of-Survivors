# Merge all cpp files in library
set(TARGET_NAME game_map)

add_library(${TARGET_NAME}
    game_map.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    graphics
    game_objects
)
