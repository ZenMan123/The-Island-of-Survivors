# Merge all cpp files in library
set(TARGET_NAME player)

add_library(${TARGET_NAME}
        player.cpp
        )

# Add link libraries
target_link_libraries(${TARGET_NAME}
        )
