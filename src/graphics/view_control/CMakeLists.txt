# Merge all cpp files in library
set(TARGET_NAME view_control)

add_library(${TARGET_NAME}
    camera.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    objects
)
