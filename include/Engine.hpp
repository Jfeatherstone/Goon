#pragma once

#include <SFML/Graphics.hpp>

#include "Card.hpp"
#include "CardInstance.hpp"
#include "external/ResourceManager.hpp"
#include "Player.hpp"
#include "Scene/MainMenu.hpp"

#include <iostream>

class Engine {

private: 

    /**
     * @brief The name of the game that will be shown in the window title bar
     */
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

    // We have several different scenes that represent different parts of the game

    MainMenu m_mainMenu;

    /**
     * @brief This is the "stack" that will handle the interaction between scenes.
     * The top most scene will be the only one to have its input taken, while all
     * active scenes will be updated and drawn, just in the reverse order that they are
     * present in the "stack".
     */
    std::vector<Scene> m_sceneStack;

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

    /**
     * @brief Setup the different scenes, including the main menu, the options menus, etc.
     */
    void initializeScenes();

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
    void draw();


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