#include <configuration/game_config.hpp>
#include <physics/physical_objects/physical_object.hpp>

class Player : public PhysicalObject {
    using Base = PhysicalObject;

public:
    Player();

    void Init();

    void Update(double time);

    void ProcessEvent(const sf::Event& event);

private:
    app_config::game::GameActions get_game_action_(const sf::Event& event);

    void process_event_pressed_(const sf::Event& event);

    void process_event_released_(const sf::Event& event);

    void start_move_left_();

    void start_move_right_();

    void stop_move_();
};