# Merge all cpp files in library
set(TARGET_NAME resources)

add_library(${TARGET_NAME}
    circle_resource.cpp
    rectangle_resource.cpp
    resource_interface.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    math
)
