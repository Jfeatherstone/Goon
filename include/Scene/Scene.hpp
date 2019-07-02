#pragma once

#include <SFML/Graphics.hpp>

#include "external/ResourceManager.hpp"


/**
 * @brief These represent the different types of scenes that may be active at any given time.
 * They are given integer values such that they hold a certain order, and that some will
 * always be displayed on top of others (eg. the pause menu should never be below the game instance)
 */
enum class SceneType: int {
    OptionsMenu = 0,
    PauseMenu = 1,
    CardCollection = 2,
    GameSelect = 3,
    MainMenu = 4,
    GameInstance = 5,
};


class Scene: public sf::Drawable {

protected:

    /**
     * @brief The default background color is black
     */
    const static sf::Color DEFAULT_BACKGROUND_COLOR;

    /**
     * @brief This will determine whether or not the background can be seen through.
     * For an in game menu, this will be true (<1), whereas for the main menu or for
     * actual game scenes, it will be false (1)
     */
    float m_backgroundTransparency;

    /**
     * @brief The color of the background of the scene
     */
    sf::Color m_backgroundColor;

    /**
     * @brief The object that will be drawn as the background
     */
    sf::RectangleShape m_background;

    /**
     * @brief The size of the window, to be passed from the engine class
     */
    sf::Vector2f m_windowSize;

public:

    Scene();

    // Some basic getter methods

    sf::RectangleShape getBackground();

    void setBackgroundColor(sf::Color backgroundColor);

    void setBackgroundTransparency(float transparency);

    float getBackgroundTransparency();

    sf::Color getBackgroundColor();


    /**
     * @brief Performs any initialization for the scene, since we want to avoid using constructors
     * 
     * @param m_windowSize The size of the window that the scene exists in
     */
    virtual void init(sf::Vector2f m_windowSize);
    /**
     * @brief The pure virtual function that handles the input for a given scene
     * 
     * @param elapsedTime The time that has passed (in seconds) since the last frame
     */
    virtual std::set<SceneType> input(sf::RenderWindow& window, float elapsedTime);
    /**
     * @brief The pure virtual function that updates variables for a given scene
     * 
     * @param elapsedTime The time that has passed (in seconds) since the last frame
     */
    virtual void update(sf::RenderWindow& window, float elapsedTime);

    /**
     * @brief This is formatted slightly differently from the update and input methods as
     * it is inhereted from the Drawable class, and allows a Scene object itself to be
     * drawn.
     * 
     * @param target The window the the scene will be drawn to
     * @param state No idea ?
     */
    virtual void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};