#pragma once

#include "Scene.hpp"

class OptionsMenu: public Scene {

public:

    OptionsMenu();

    // The virtual methods from Scene
    void init(sf::Vector2f windowSize);
    std::vector<SceneType> input(sf::RenderWindow& window, float elapsedTime);
    void update(sf::RenderWindow& window, float elapsedTime);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

};