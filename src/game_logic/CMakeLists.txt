# Add source directories
add_subdirectory(game_map)
add_subdirectory(player)

# Merge all cpp files in library
set(TARGET_NAME game_logic)

add_library(${TARGET_NAME}
        game.cpp
        )

# Add link libraries
target_link_libraries(${TARGET_NAME}
        game_map
        graphics
        player
        physics
        )
