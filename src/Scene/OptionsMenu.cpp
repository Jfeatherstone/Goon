#include "Scene/OptionsMenu.hpp"

void OptionsMenu::init(sf::Vector2f windowSize) {

}

std::vector<SceneType> OptionsMenu::input(sf::RenderWindow& window, float elapsedTime) {
    
    std::vector<SceneType> scenes;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        scenes.push_back(SceneType::OptionsMenu);
    }


    return scenes;
}

void OptionsMenu::update(sf::RenderWindow& window, float elapsedTime) {

}

void OptionsMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

}