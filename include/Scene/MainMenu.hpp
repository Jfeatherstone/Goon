#pragma once

#include "Scene/Scene.hpp"

class MainMenu: public Scene {

private:

    const static sf::Color DEFAULT_TEXT_COLOR;
    const static sf::Color HIGHLIGHT_TEXT_COLOR;

    /**
     * @brief The text displaying the title
     */
    sf::Text m_titleText;

    sf::Text m_playGameText;

    sf::Text m_cardCollectionText;

    sf::Text m_optionsText;

    sf::Text m_exitText;

public:

    MainMenu();

    // The virtual methods from Scene
    void init(sf::Vector2f windowSize);
    void input(sf::RenderWindow& window, float elapsedTime);
    void update(sf::RenderWindow& window, float elapsedTime);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

};