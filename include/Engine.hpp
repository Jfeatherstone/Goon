#pragma once

#include <SFML/Graphics.hpp>

#include "Card.hpp"
#include "CardInstance.hpp"
#include "external/ResourceManager.hpp"
#include "Player.hpp"

class Engine {
    
    /**
     * @brief The window that we will be drawing everything on
     */
    sf::RenderWindow m_window;

    /**
     * @brief Keeping track of how large the window is
     */
    sf::Vector2f m_windowSize;

    // Some bools for keeping track of what is going on in the game currently
    bool m_inMainMenu;
    bool m_inPauseMenu;
    bool m_inGame;

    /**
     * @brief Keeping track of whose turn it it
     */
    bool m_isPlayerOnesTurn;

    /**
     * @brief The first player, which will be the local player if the match is online
     */
    Player m_playerOne;

    /**
     * @brief The second player, which will be the remote player if the match is online
     */
    Player m_playerTwo;

    /**
     * @brief Whether or not the game is online or local
     */
    bool m_isOnline;
};