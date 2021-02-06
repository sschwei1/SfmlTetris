#include "MainMenuState.h"

void MainMenuState::initKeybinds() {
//    this->keybinds["END_STATE"] = this->supportedKeys->at("ESC");
    std::ifstream ifs("config/gamestate_keybinds.ini");

    if(ifs.is_open()){
        std::string action;
        std::string key;

        while(ifs >> action >> key){
            this->keybinds[action] = this->supportedKeys->at(key);
        }
    }

    ifs.close();
}

MainMenuState::MainMenuState(sf::RenderWindow* window , std::map<std::string, sf::Keyboard::Key>* supportedKeys)
        : State(window, supportedKeys) {
    this->initKeybinds();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Green);
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::endState() {
    std::cout << "Ending MainMenuState" << "\n";
}

void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();

    // update player input
}

void MainMenuState::update(const float& dt) {
    this->updateInput(dt);
}

void MainMenuState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->window;

    target->draw(this->background);
}