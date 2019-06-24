#pragma once

#include <SFML/Graphics.hpp>

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
    
};