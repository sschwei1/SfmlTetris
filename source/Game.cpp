#include "Game.h"

// Static functions

// Initializer functions
void Game::initWindow() {
    std::ifstream ifs("config/window.ini");

    std::string title = "Application";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;

    if(ifs.is_open()){
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }

    ifs.close();

    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

// Constructor/Destructor
Game::Game() {
    this->initWindow();
}

Game::~Game() {
    delete this->window;
}

// Functions
void Game::updateDt() {
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents() {
    while (this->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed){
            this->window->close();
        }
    }
}

void Game::update() {
    this->updateSFMLEvents();
}

void Game::render() {
    this->window->clear();
    this->window->display();
}

void Game::run() {
    while (this->window->isOpen()){
        this->updateDt();
        this->update();
        this->render();
    }
}


