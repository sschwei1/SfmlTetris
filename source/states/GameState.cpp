//
// Created by 24seb on 24/11/2020.
//

#include "GameState.h"

void GameState::initKeybinds() {
    this->keybinds.emplace("END_STATE", this->supportedKeys->at("ESC"));
    this->keybinds.emplace("MOVE_LEFT", this->supportedKeys->at("A"));
    this->keybinds.emplace("MOVE_RIGHT", this->supportedKeys->at("D"));
    this->keybinds.emplace("MOVE_UP", this->supportedKeys->at("W"));
    this->keybinds.emplace("MOVE_DOWN", this->supportedKeys->at("S"));
}

GameState::GameState(sf::RenderWindow* window , std::map<std::string, sf::Keyboard::Key>* supportedKeys)
    : State(window, supportedKeys) {
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
    this->updateInput(dt);

    this->tile.update(dt);
}

void GameState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->window;

    this->tile.render(target);
}
