//
// Created by 24seb on 23/11/2020.
//

#include "State.h"

State::State(sf::RenderWindow* window) {
    this->window = window;
    this->quit = false;
}

State::~State() {

}

const bool &State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
        this->quit = true;
    }
}