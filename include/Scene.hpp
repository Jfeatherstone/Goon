#pragma once

#include <SFML/Graphics.hpp>

class Scene: public sf::Drawable {

private:

    /**
     * @brief This will determine whether or not the background can be seen through.
     * For an in game menu, this will be true (<1), whereas for the main menu or for
     * actual game scenes, it will be false (1)
     */
    float m_backgroundTransparency;

public:

    Scene() {

    }

    /**
     * @brief The pure virtual function that handles the input for a given scene
     * 
     * @param elapsedTime The time that has passed (in seconds) since the last frame
     */
    virtual void input(float elapsedTime);
    /**
     * @brief The pure virtual function that updates variables for a given scene
     * 
     * @param elapsedTime The time that has passed (in seconds) since the last frame
     */
    virtual void update(float elapsedTime);

    /**
     * @brief This is formatted slightly differently from the update and input methods as
     * it is inhereted from the Drawable class, and allows a Scene object itself to be
     * drawn.
     * 
     * @param target The window the the scene will be drawn to
     * @param state No idea ?
     */
    void draw(sf::RenderTarget& target, sf::RenderStates state) const;
};