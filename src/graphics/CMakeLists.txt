# Add source directories
add_subdirectory(camera)
add_subdirectory(drawable)

# Marge all cpp files in library
set(TARGET_NAME graphics)

add_library(${TARGET_NAME}
    graphics_context.cpp
    graphics_engine.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    drawable
    physical_objects
)
