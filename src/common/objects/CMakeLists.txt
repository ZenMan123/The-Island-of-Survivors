# Merge all cpp files in library
set(TARGET_NAME objects)

add_library(${TARGET_NAME}
    follow_object.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    math
)
