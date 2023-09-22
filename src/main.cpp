#include <SFML/Window/WindowStyle.hpp>
#include <algorithm>
#include <graphics/graphics_engine.hpp>


int main() {
    sf::VideoMode::getDesktopMode();

    Resource::Ptr resource = std::make_unique<ColorResource>(sf::Color(255, 0, 0));

    Vec2 position(0.0);
    Vec2 size(100.0);
    DrawableObject::Ptr object = std::make_shared<DrawableObject>(position, size, std::move(resource));

    RenderWindowPtr window = GraphicsEngine::create_window("Hello world window", sf::Style::Default);
    GraphicsEngine graphics_engine(window);

    GraphicsContext::GetInstance()->drawable_objects.insert(std::move(object));

    while (window->isOpen()) {
        for (sf::Event event; window->pollEvent(event);) {
            if (event.type == sf::Event::Closed) {
                window->close();
            }
        }

        window->clear(sf::Color::Black);

        graphics_engine.draw();

        window->display();
    }

    return 0;
}
