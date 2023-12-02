# Add source directories
add_subdirectory(resources)

# Merge all cpp files in library
set(TARGET_NAME drawable_objects)

add_library(${TARGET_NAME}
    drawable_object.cpp
    sprite.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    resources
    view_control
)
