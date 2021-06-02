#include "MainMenuState.h"

void MainMenuState::initFonts() {
    if(!this->font.loadFromFile("fonts/Overpass-Light.ttf")){
        throw("ERROR::MAIN_MENU_STATE::COULD_NOT_LOAD_FONT");
    }
}

void MainMenuState::initKeybinds() {
//    this->keybinds["END_STATE"] = this->supportedKeys->at("ESC");
    std::ifstream ifs("config/gamestate_keybinds.ini");

    if(ifs.is_open()){
        std::string action;
        std::string key;

        while(ifs >> action >> key){
            this->keybinds[action] = this->supportedKeys->at(key);
        }
    }

    ifs.close();
}

void MainMenuState::initButtons() {
    this->buttons["GAME_STATE"] = new Button(100, 100, 150, 50,
         &this->font, "New Game",
         sf::Color(70,70,70,200), sf::Color(150,150,150,200), sf::Color(20,20,20,200));

    this->buttons["EXIT_STATE"] = new Button(100, 300, 150, 50,
         &this->font, "Quit",
         sf::Color(100,100,100,200), sf::Color(150,150,150,200), sf::Color(20,20,20,200));

}

MainMenuState::MainMenuState(sf::RenderWindow* window,std::stack<State*>* states, std::map<std::string, sf::Keyboard::Key>* supportedKeys)
        : State(window, states, supportedKeys) {
    this->initFonts();
    this->initKeybinds();
    this->initButtons();

    this->background.setSize(sf::Vector2f(window->getSize().x, window->getSize().y));
    this->background.setFillColor(sf::Color::Green);
}

MainMenuState::~MainMenuState() {
    for(auto & button : this->buttons){
        delete button.second;
    }
}

void MainMenuState::endState() {
    std::cout << "Ending MainMenuState" << "\n";
}

void MainMenuState::updateInput(const float &dt) {
    this->checkForQuit();

    // update player input
}

void MainMenuState::updateButtons() {
    for(auto &it : this->buttons){
        it.second->update(this->mousePosView);
    }

    if(this->buttons["GAME_STATE"]->isPressed()){
        this->states->push(new GameState(this->window, this->states, this->supportedKeys));
    }

    if(this->buttons["EXIT_STATE"]->isPressed()){
        this->quit = true;
    }
}

void MainMenuState::update(const float& dt) {
    this->updateMousePositions();
    this->updateInput(dt);
    this->updateButtons();
}

void MainMenuState::renderButtons(sf::RenderTarget *target) {
    for(auto &it : this->buttons){
        it.second->render(target);
    }
}

void MainMenuState::render(sf::RenderTarget* target) {
    if(!target)
        target = this->window;

    target->draw(this->background);
    this->renderButtons(target);
}

void MainMenuState::checkForQuit() {
//    if(sf::Keyboard::isKeyPressed(this->keybinds.at("END_STATE"))){
//        this->quit = true;
//    }
}