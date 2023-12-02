#pragma once

#include <game_logic/game.hpp>

class AppRunner {
public:
    AppRunner();
    void init();
    void draw() const;
    void update(double time);
    void run();

private:
    Game game_;
    RenderWindowPtr window_;
};