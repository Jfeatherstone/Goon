#pragma once

#include <SFML/Graphics.hpp>
#include "CardInstance.hpp"

class Lane {

private:

    /**
     * @brief The default border for each lane. This may be changed if a card played in the lane
     * has a special effect.
     */
    const static sf::Texture DEFAULT_LANE_BORDER;

    /**
     * @brief The current health of the lane
     */
    int m_currentHealth;

    /**
     * @brief The maximum and starting health of the lane
     */
    int m_maxHealth;

    /**
     * @brief The current border texture for the lane
     */
    sf::Texture m_laneBorder;

    /**
     * @brief The background color of the lane
     */
    sf::Color m_laneBackground;

    /**
     * @brief The image that will be use for the health in the lane
     */
    sf::Texture m_healthTexture;

    /**
     * @brief The combined sprite of the lane, including the border, background, and health bar
     */
    sf::Sprite m_sprite;

    /**
     * @brief The cards that are played in the lane
     */
    std::vector<CardInstance> m_cards;

    /**
     * @brief The number of cards played in the lane
     * i.e. the size of m_cards
     */
    int m_numCards;

public:

};