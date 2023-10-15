# Merge all cpp files in library
set(TARGET_NAME player)

add_library(${TARGET_NAME}
    player.cpp
    player_condition.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    sfml-graphics
    physical_objects
)
