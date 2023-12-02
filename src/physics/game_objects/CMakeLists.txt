# Merge all cpp files in library
set(TARGET_NAME game_objects)

add_library(${TARGET_NAME}
    game_object.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    drawable_objects
    physical_objects
)
