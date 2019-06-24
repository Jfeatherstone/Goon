#pragma once

#include <SFML/Graphics.hpp>

/**
 * @brief 
 * 
 */
namespace abl {

    /**
     * @brief 
     * 
     */
    enum Passive {
        
    };

    /**
     * @brief 
     * 
     */
    enum Active {
        
    };
}

class Card {

public:
    /**
     * @brief This is the size of the image that will appear on every card
     */
    const static sf::Vector2i IMAGE_DIMENSIONS;

private:

    /**
     * @brief The name of the card to appear on the screen
     */
    std::string m_name;

    /**
     * @brief The non-interactive text to appear on the card
     */
    std::string m_flavourText;

    /**
     * @brief The power level of the card, which contributes to its offense or defense
     */
    int m_powerLevel;

    /**
     * @brief The image to appear on the card
     * TODO: Decide on a standard resolution for these
     */
    sf::Texture* m_texture;

    /**
     * @brief 
     */
    std::vector<abl::Active> m_activeAbilities;

    /**
     * @brief 
     */
    std::vector<abl::Passive> m_passiveAbilities;

public:

    /**************************************
     *           BASIC GETTERS
     * These methods return exactly the member variables described
     * by the title of the function
     **************************************/

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName();

    /**
     * @brief Get the Flavour Text object
     * 
     * @return std::string 
     */
    std::string getFlavourText();

    /**
     * @brief Get the Power Level object
     * 
     * @return int 
     */
    int getPowerLevel();

    /**
     * @brief Get the Texture pointer
     * 
     * @return sf::Texture*
     */
    sf::Texture* getTexture();

    /**
     * @brief Get the Active Abilities vector
     * 
     * @return std::vector<abl::Active> 
     */
    std::vector<abl::Active> getActiveAbilities();

    /**
     * @brief Get the Passive Abilities vector
     * 
     * @return std::vector<abl::Passive> 
     */
    std::vector<abl::Passive> getPassiveAbilities();

    /**************************************
     *           CONSTRUCTORS
     **************************************/
    
    /**
     * @brief Construct a new Card object
     * 
     * @param name 
     * @param flavourText 
     * @param powerLevel 
     * @param texture 
     * @param activeAbilities 
     * @param passiveAbilities 
     */
    Card(std::string name, std::string flavourText, int powerLevel,
     sf::Texture* texture, std::vector<abl::Active> activeAbilities = {},
      std::vector<abl::Passive> passiveAbilities = {});

    /**
     * @brief Construct an empty Card object
     */
    Card();

    /**************************************
     *           ADVANCED GETTERS
     * These methods return modified or calculated values from
     * the member variables (as opposed to basic getters above)
     **************************************/

    /**
     * @brief Using the power level of the card, calculate the offensive power. This will be
     * exactly equal to the power level in most scenarios, execpt when the card has a passive
     * ability that augments it.
     * 
     * @return int 
     */
    int getOffense();

    /**
     * @brief Using the power level of the card, calculate the defensive power. This will be
     * exactly equal to the power level in most scenarios, execpt when the card has a passive
     * ability that augments it.
     * 
     * @return int 
     */
    int getDefense();

};