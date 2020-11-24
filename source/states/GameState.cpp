//
// Created by 24seb on 24/11/2020.
//

#include "GameState.h"

GameState::GameState(sf::RenderWindow* window) : State(window) {

}

GameState::~GameState() {

}

void GameState::endState() {

}

void GameState::update(const float& dt) {
    std::cout << "Hello from GameState" << "\n";
}

void GameState::render(sf::RenderTarget* target) {

}
