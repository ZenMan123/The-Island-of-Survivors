#pragma once

#include <game_logic/game.hpp>
#include <graphics/graphics_engine.hpp>
#include <SFML/Graphics.hpp>

class AppRunner {
public:
    AppRunner();
    void Init();
    void Draw() const;
    void Update(double time);
    void run();

private:
    Game game_;
    RenderWindowPtr window_;
};