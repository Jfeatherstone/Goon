#pragma once

#include <SFML/Graphics.hpp>
#include "Card.hpp"

class CardInstance {
    
private:

    /**
     * @brief The card that this object is an instance of
     */
    Card m_card;

    sf::Sprite m_sprite;
};