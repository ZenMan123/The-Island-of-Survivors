# Add source directories
add_subdirectory(drawable_objects)
add_subdirectory(resource_managers)
add_subdirectory(view_control)

# Merge all cpp files in library
set(TARGET_NAME graphics)

add_library(${TARGET_NAME}
    graphics_context.cpp
    graphics_engine.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    drawable_objects
)
