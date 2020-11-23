#ifndef SFMLTETRIS_STATE_H
#define SFMLTETRIS_STATE_H

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

class State {
private:
    std::vector<sf::Texture> textures;


public:
    State();
    virtual ~State();

    virtual void update() = 0;
    virtual void render() = 0;
};

#endif //SFMLTETRIS_STATE_H
