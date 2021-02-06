#ifndef SFMLTETRIS_MAINMENUSTATE_H
#define SFMLTETRIS_MAINMENUSTATE_H

#include "GameState.h"
#include "../resources/Button.h"

class MainMenuState : public State {
private:
    // variables
    sf::RectangleShape background;
    sf::Font font;

    Button* gamestate_btn;

    // functions
    void initFonts();
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys);
    virtual ~MainMenuState();

    // Functions
    void endState();
    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};


#endif //SFMLTETRIS_MAINMENUSTATE_H
