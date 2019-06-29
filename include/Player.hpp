#pragma once

#include "Card.hpp"
#include "CardInstance.hpp"
#include <SFML/Graphics.hpp>

class Player {

private:

    /**
     * @brief The cards that are currently visible and playable to the player
     */
    std::vector<Card> m_cardsInHand;
    
    /**
     * @brief The cards that can be drawn into the player's hand on a draw
     */
    std::vector<Card> m_cardsInDeck;

public:

    /**
     * @brief Moves a set number of cards from the player's deck to their hand
     * 
     * @param numCards The number of cards to be moved, defaults to 1
     * @return Card The card(s) that were drawn
     */
    std::vector<Card> drawCard(int numCards = 1);

    /**
     * @brief The meat of the player class, allows the user to take action for a limited
     * amount of time during their turn. This will hold until either the time limit is up
     * or the player ends their turn
     * 
     * @param timeLimit The amount of time before the player's turn is forcably ended
     * @return bool Will return true if the 
     */
    bool takeTurn(int timeLimit);

};