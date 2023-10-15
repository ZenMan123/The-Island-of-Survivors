# Add source directories
add_subdirectory(physical_objects)

# Marge all cpp files in library
set(TARGET_NAME physics)

add_library(${TARGET_NAME}
    physical_context.cpp
    physical_engine.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    physical_objects
)
