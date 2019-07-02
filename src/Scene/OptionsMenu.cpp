#include "Scene/OptionsMenu.hpp"

void OptionsMenu::init(sf::Vector2f windowSize) {

}

std::set<SceneType> OptionsMenu::input(sf::RenderWindow& window, float elapsedTime) {
    
    std::set<SceneType> scenes;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
        scenes.insert(SceneType::OptionsMenu);
    }


    return scenes;
}

void OptionsMenu::update(sf::RenderWindow& window, float elapsedTime) {

}

void OptionsMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

}