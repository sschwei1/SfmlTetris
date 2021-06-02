//
// Created by 24seb on 23/11/2020.
//

#include "State.h"

State::State(sf::RenderWindow* window, std::stack<State*>* states, std::map<std::string, sf::Keyboard::Key>* supportedKeys) {
    this->window = window;
    this->states = states;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}

State::~State() {

}

const bool &State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {

}

void State::updateMousePositions() {
    this->mousePosScreen = sf::Mouse::getPosition();
    this->mousePosWindow = sf::Mouse::getPosition(*this->window);
    this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}