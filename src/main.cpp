#include <graphics/graphics_engine.hpp>
#include <configuration/game_config.hpp>
#include <runtime/app_runner.hpp>

int main() {
    AppRunner app_runner;
    app_runner.Init();
    app_runner.run();
    return 0;
}
