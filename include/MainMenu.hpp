#pragma once

#include "Scene.hpp"

class MainMenu: public Scene {

public:

    MainMenu();

    void draw(sf::RenderTarget& target, sf::RenderStates state) const;

};