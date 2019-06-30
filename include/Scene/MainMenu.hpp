#pragma once

#include "Scene/Scene.hpp"

class MainMenu: public Scene {

private:

    /**
     * @brief The text displaying the title
     */
    sf::Text m_titleText;
    

public:

    MainMenu();

    // The virtual methods from Scene
    void init(sf::Vector2f windowSize);
    void input(float elapsedTime);
    void update(float elapsedTime);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

};