# Marge all cpp files in library
set(TARGET_NAME runtime)

add_library(${TARGET_NAME}
    game_runner.cpp
)

# Add link libraries
target_link_libraries(${TARGET_NAME}
    graphics
)
