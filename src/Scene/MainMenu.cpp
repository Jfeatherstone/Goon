#include "Scene/MainMenu.hpp"

#include <iostream>

MainMenu::MainMenu() {

}

void MainMenu::init(sf::Vector2f windowSize) {

    m_windowSize = windowSize;

    setBackgroundTransparency(1.0f);

    m_background.setFillColor(DEFAULT_BACKGROUND_COLOR);
    m_background.setSize(m_windowSize);

    m_titleText.setFont(*ResourceManager::getFont("assets/fonts/KarmaFuture.ttf"));
    m_titleText.setString("Goon");
    m_titleText.setCharacterSize(120);
    m_titleText.setOrigin(m_titleText.getLocalBounds().width / 2, m_titleText.getLocalBounds().height / 2);
    m_titleText.setPosition(m_windowSize.x / 2, m_windowSize.y / 6);

}

void MainMenu::input(float elapsedTime) {

}

void MainMenu::update(float elapsedTime) {

}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

    // First we draw the background
    target.draw(m_background);

    target.draw(m_titleText);

    //std::cout << "Drawing main menu" << std::endl;
}