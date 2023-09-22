# Marge all cpp files in library
set(TARGET_NAME physics)

add_library(${TARGET_NAME}
    physic_object.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    math
)
