#pragma once

#include <SFML/Graphics.hpp>
#include "Card.hpp"

/**
 * @brief The possible places a card instance could be on the board. Cards that have been destroyed/
 * removed/played will have their object deleted altogether, and thus do not need a location.
 */
enum Location {
    Left,
    Right,
    Middle,
    Hand,
    Deck
};

class CardInstance {
    
private:

    /**
     * @brief The card that this object is an instance of
     */
    Card m_card;

    /**
     * @brief Where the card instance is located on the board
     */
    Location m_location;

    sf::Sprite m_sprite;
};