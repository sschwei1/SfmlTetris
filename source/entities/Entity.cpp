//
// Created by 24seb on 25/11/2020.
//

#include "Entity.h"

Entity::Entity() {
    this->shape.setSize(sf::Vector2(50.f,50.f));
    this->shape.setFillColor(sf::Color::White);
    this->movementSpeed = 100.f;
}

Entity::~Entity() {

}

void Entity::move(const float& dt, const float dir_x, const float dir_y) {
    this->shape.move(dir_x * this->movementSpeed * dt, dir_y * this->movementSpeed * dt);
}

void Entity::update(const float &dt) {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
        this->move(dt, -1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
        this->move(dt, 1.f, 0.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
        this->move(dt, 0.f, -1.f);
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
        this->move(dt, 0.f, 1.f);
    }

    /*
     * 0 => A
     * 1 => B
     * 2 => X
     * 3 => Y
     * 4 => LB
     * 5 => RB
     * 6 => Back
     * 7 => Start
     * 8 => JL
     * 9 => JR
     */

    if(sf::Joystick::isConnected(0)){
        int th = 30;
        float posX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
        float posY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

        if(abs(posX) < 30){
            posX = 0;
        }
        if(abs(posY) < 30){
            posY = 0;
        }

        std::cout << "X:" << posX << " Y:" << posY << "\n";

        this->move(dt, posX/100, posY/100);
    }
}

void Entity::render(sf::RenderTarget* target) {
    target->draw(this->shape);
}
