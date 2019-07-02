#pragma once

#include "Scene.hpp"

class OptionsMenu: public Scene {

private:

public:

    // The virtual methods from Scene
    void init(sf::Vector2f windowSize);
    std::set<SceneType> input(sf::RenderWindow& window, float elapsedTime);
    void update(sf::RenderWindow& window, float elapsedTime);
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

};