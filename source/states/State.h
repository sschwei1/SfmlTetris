#ifndef SFMLTETRIS_STATE_H
#define SFMLTETRIS_STATE_H

#include "../entities/Entity.h"

class State {
protected:
    sf::RenderWindow* window;
    std::map<std::string, sf::Keyboard::Key>* supportedKeys;
    std::map<std::string, sf::Keyboard::Key> keybinds;
    bool quit;

    sf::Vector2i mousePosScreen;
    sf::Vector2i mousePosWindow;
    sf::Vector2f mousePosView;

    // resources
    std::vector<sf::Texture> textures;

    // functions
    virtual void initKeybinds() = 0;

public:
    State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
    virtual ~State();

    const bool& getQuit() const;

    virtual void checkForQuit();

    virtual void endState() = 0;
    virtual void updateMousePositions();
    virtual void updateInput(const float& dt) = 0;
    virtual void update(const float& dt) = 0;
    virtual void render(sf::RenderTarget* target = nullptr) = 0;
};

#endif //SFMLTETRIS_STATE_H
