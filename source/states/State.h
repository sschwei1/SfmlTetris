#ifndef SFMLTETRIS_STATE_H
#define SFMLTETRIS_STATE_H

#include "../entities/Entity.h"

class State {
protected:
    sf::RenderWindow* window;
    std::vector<sf::Texture> textures;
    bool quit;

public:
    const bool& getQuit() const;

    State(sf::RenderWindow* window);
    virtual ~State();

    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateKeybinds(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif //SFMLTETRIS_STATE_H
