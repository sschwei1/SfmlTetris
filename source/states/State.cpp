//
// Created by 24seb on 23/11/2020.
//

#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, sf::Keyboard::Key>* supportedKeys) {
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}

State::~State() {

}

const bool &State::getQuit() const {
    return this->quit;
}

void State::checkForQuit() {
    if(sf::Keyboard::isKeyPressed(this->keybinds.at("END_STATE"))){
        this->quit = true;
    }
}