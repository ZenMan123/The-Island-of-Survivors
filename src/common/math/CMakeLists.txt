# Marge all cpp files in library
set(TARGET_NAME math)

add_library(${TARGET_NAME}
    vec2.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    utils
    sfml-graphics
)
