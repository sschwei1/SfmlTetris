//
// Created by 24seb on 24/11/2020.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}

GameState::~GameState() {

}

void GameState::endState() {
    std::cout << "Ending GameState" << "\n";
}

void GameState::updateKeybinds(const float &dt) {
    this->checkForQuit();
}

void GameState::update(const float& dt) {
    this->updateKeybinds(dt);

    this->tile.update(dt);
}

void GameState::render(sf::RenderTarget* target) {
    this->tile.render(target == nullptr ? target : this->window);
}
