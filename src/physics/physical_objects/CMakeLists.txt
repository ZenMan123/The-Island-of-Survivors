# Marge all cpp files in library
set(TARGET_NAME physical_objects)

add_library(${TARGET_NAME}
    object_border.cpp
    physical_object.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    math
)
