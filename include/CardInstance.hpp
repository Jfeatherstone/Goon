#pragma once

#include <SFML/Graphics.hpp>
#include "Card.hpp"

class CardInstance {
    
private:

    /**
     * @brief The card that this object is an instance of
     */
    Card m_card;

    /**
     * @brief The part of the class that will be drawn on a window when the card is face up
     */
    sf::Texture m_frontTexture;

    /**
     * @brief The part of the class that will be drawn on a window when the card is face up
     */
    sf::Texture m_backTexture;

    /**
     * @brief The object that will be drawn to the screen
     */
    sf::Sprite m_sprite;

    /**
     * @brief Whether the card is face up or face down
     */
    bool m_isFaceUp;
};