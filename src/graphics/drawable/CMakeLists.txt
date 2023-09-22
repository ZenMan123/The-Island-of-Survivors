# Marge all cpp files in library
set(TARGET_NAME drawable)

add_library(${TARGET_NAME}
    drawable_object.cpp
    resource.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    math
)
