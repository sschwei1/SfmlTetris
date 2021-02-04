#ifndef SFMLTETRIS_GAMESTATE_H
#define SFMLTETRIS_GAMESTATE_H

#include "State.h"

class GameState : public State {
private:
    Entity tile;

    // functions
    void initKeybinds();

public:
    GameState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
    virtual ~GameState();

    // Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};


#endif //SFMLTETRIS_GAMESTATE_H
