#ifndef SFMLTETRIS_GAME_H
#define SFMLTETRIS_GAME_H

#include "states/MainMenuState.h"


class Game {
private:
    // Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    std::map<std::string, sf::Keyboard::Key> supportedKeys;

    // Initializer functions
    void initWindow();
    void initKeys();
    void initStates();

public:
    // Constructor/Destructor
    Game();
    virtual ~Game();

    // Functions

    // Regular
    void endApplication();

    // update
    void updateDt();
    void updateSFMLEvents();
    void update();

    // render
    void render();

    // core
    void run();
};


#endif
