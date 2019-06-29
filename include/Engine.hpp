#pragma once

#include <SFML/Graphics.hpp>

#include "Card.hpp"
#include "CardInstance.hpp"
#include "external/ResourceManager.hpp"
#include "Player.hpp"

#include <iostream>

class Engine {

private: 

    const static std::string GAME_NAME;

    /**
     * @brief The window that we will be drawing everything on
     */
    sf::RenderWindow m_window;

    /**
     * @brief Keeping track of how large the window is
     */
    sf::Vector2f m_windowSize;

    /**
     * @brief The default window size: 800x600
     */
    const static sf::Vector2f DEFAULT_WINDOW_SIZE;

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

    /*******************************************************
     *                 INITIALIZATION METHODS
     * The following methods setup different variables before
     * the game loop can begin
     *******************************************************/

    /**
     * @brief Setup the window dimensions, limit FPS, and other initialization tasks
     */
    void initializeWindow(sf::Vector2f windowSize);

    /**
     * @brief Load the assets including sounds, textures and fonts
     */
    void initializeAssets();

    /*******************************************************
     *                   GAME LOOP METHODS
     * The following methods are defined each in their own files
     * called Input.cpp, Update.cpp, and Draw.cpp, respectively
     *******************************************************/

    /**
     * @brief Handle any input in the last frame
     * First of the 3 game loop methods
     * 
     * @param elapsedTime The amount of time since the last game loop iteration
     */
    void input(float elapsedTime);
    /**
     * @brief Update any positions/velocities/health etc. based on previous events
     * Second of the 3 game loop methods
     * 
     * @param elapsedTime The amount of time since the last game loop iteration
     */
    void update(float elapsedTime);
    /**
     * @brief Draw the newly updated sprites onto the screen
     * Third of the 3 game loop methods 
     * 
     * @param elapsedTime The amount of time since the last game loop iteration
     */
    void draw(float elapsedTime);


public:
    
    /**
     * @brief This constructor will run all of the initialize methods above
     */
    Engine(sf::Vector2f windowSize = DEFAULT_WINDOW_SIZE);

    /**
     * @brief This will run the main game loop, which will exit when the window is closed
     */
    void run();
};