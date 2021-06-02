//
// Created by 24seb on 24/11/2020.
//

#include "GameState.h"

void GameState::initKeybinds() {
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

GameState::GameState(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, sf::Keyboard::Key>* supportedKeys)
    : State(window, states, supportedKeys) {
    this->initKeybinds();
}

GameState::~GameState() {

}

void GameState::endState() {
    std::cout << "Ending GameState" << "\n";
}

void GameState::updateInput(const float &dt) {
    this->checkForQuit();

    // update player input
    if(sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_LEFT")))
        this->tile.move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_RIGHT")))
        this->tile.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_UP")))
        this->tile.move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(this->keybinds.at("MOVE_DOWN")))
        this->tile.move(dt, 0.f, 1.f);
}

void GameState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);

    this->tile.update(dt);
}

void GameState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->window;

    this->tile.render(target);
}

void GameState::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(this->keybinds.at("END_STATE"))){
        this->quit = true;
    }
}
