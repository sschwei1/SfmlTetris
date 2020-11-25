#ifndef SFMLTETRIS_ENTITY_H
#define SFMLTETRIS_ENTITY_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <stdlib.h>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class Entity {
protected:
    sf::RectangleShape shape;
    float movementSpeed;

public:
    Entity();
    virtual ~Entity();

    // Functions
    void move(const float& dt, const float dir_x, const float dir_y);

    virtual void update(const float& dt);
    virtual void render(sf::RenderTarget* target);
};


#endif //SFMLTETRIS_ENTITY_H
