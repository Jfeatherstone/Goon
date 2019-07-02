#include "Scene/OptionsMenu.hpp"

void OptionsMenu::init(sf::Vector2f windowSize) {

    m_windowSize = windowSize;

    setBackgroundTransparency(.70f);

    setBackgroundTransparency(.70f);
    m_background.setSize(m_windowSize);

}

std::set<SceneType> OptionsMenu::input(sf::RenderWindow& window, float elapsedTime) {
    
    std::set<SceneType> scenes;

    sf::Event event;

    while (window.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed) {

            if (event.key.code == sf::Keyboard::Escape)
                scenes.insert(SceneType::OptionsMenu);

        }

    }

    return scenes;
}

void OptionsMenu::update(sf::RenderWindow& window, float elapsedTime) {

}

void OptionsMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

    target.draw(m_background);

}