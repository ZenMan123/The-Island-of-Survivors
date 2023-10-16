# Merge all cpp files in library
set(TARGET_NAME drawable)

add_library(${TARGET_NAME}
    drawable_object.cpp
    resource.cpp
    sprite.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    camera
    physical_objects
)
