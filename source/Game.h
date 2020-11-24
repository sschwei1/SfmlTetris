#ifndef SFMLTETRIS_GAME_H
#define SFMLTETRIS_GAME_H

#include "states/GameState.h"


class Game {
private:
    // Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    std::stack<State*> states;

    // Initializer functions
    void initWindow();
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
