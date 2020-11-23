#ifndef SFMLTETRIS_GAME_H
#define SFMLTETRIS_GAME_H

#include "State.h"


class Game {
private:
    // Variables
    sf::RenderWindow *window;
    sf::Event sfEvent;

    sf::Clock dtClock;
    float dt;

    // Initializer functions
    void initWindow();

public:
    // Constructor/Destructor
    Game();
    virtual ~Game();

    // Functions
    void updateDt();
    void updateSFMLEvents();
    void update();
    void render();
    void run();
};


#endif
