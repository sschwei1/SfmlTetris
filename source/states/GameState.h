#ifndef SFMLTETRIS_GAMESTATE_H
#define SFMLTETRIS_GAMESTATE_H

#include "State.h"

class GameState : public State {
private:

public:
    GameState(sf::RenderWindow* window);
    virtual ~GameState();

    // Functions
    void endState();
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};


#endif //SFMLTETRIS_GAMESTATE_H
