#include "Engine.hpp"

/************************
 *    STATIC VARIABLES
 ************************/
const sf::Vector2f Engine::DEFAULT_WINDOW_SIZE = sf::Vector2f(800, 600);
const std::string Engine::GAME_NAME = "Goon";
const float Engine::VERSION = 0.1f;

Engine::Engine(sf::Vector2f windowSize) {

    initializeWindow(windowSize);
    initializeAssets();
    initializeScenes();
}

/**********************************
 *      INITIALIZATION METHODS
 **********************************/

void Engine::initializeWindow(sf::Vector2f windowSize) {

    // Make sure the window size isn't too big
    if (sf::VideoMode::getDesktopMode().width < windowSize.x ||
    sf::VideoMode::getDesktopMode().height < windowSize.y) {
        std::cout << "Resolution too large! Changing to default..." << std::endl;
        m_windowSize = DEFAULT_WINDOW_SIZE;
    }

    m_windowSize = windowSize;

    // Now create the window
    m_window.create(sf::VideoMode(m_windowSize.x, m_windowSize.y), GAME_NAME, sf::Style::Default);

    // Cap the framerate at 60 fps
    m_window.setFramerateLimit(60);

}

void Engine::initializeAssets() {
    ResourceManager::preLoadTextures("assets/");
    ResourceManager::preLoadSoundBuffers("assets/");
    ResourceManager::preLoadFonts("assets/");
}

void Engine::initializeScenes() {

    // Should be initialized in the following order:
    // Options, Pause, Card Collection, Main, Game Instance
    // This is the order that screens are displayed on top of each other
    // Note that the order initialized or added here doesn't actually matter
    // though. std::maps are ordered by comparators (<) and so each SceneType
    // is assigned an integer value, which reflect that same order as below:
    // Options = 0, ..., GameInstance = 5

    // Initialize the options menu
    m_scenes[SceneType::OptionsMenu] = new OptionsMenu();
    m_scenes[SceneType::OptionsMenu]->init(m_windowSize);
    m_scenesActive[SceneType::OptionsMenu] = false; // Disable options menu

    // Initialize the pause menu


    // Initialize the card collection


    // Initialize the game select screen
    

    // Initialize the main menu
    m_scenes[SceneType::MainMenu] = new MainMenu();
    m_scenes[SceneType::MainMenu]->init(m_windowSize);
    m_scenesActive[SceneType::MainMenu] = true; // Enable the main menu

    // Initialize the game instance


}

void Engine::run() {
    sf::Clock clock;

    while (m_window.isOpen()) {
        sf::Time dt = clock.restart();

        input(dt.asSeconds());

        update(dt.asSeconds());

        draw();

    }
}

void Engine::draw() {

    // Clear the window
    m_window.clear();

    // Now iterate backwards through the map and draw anything that is set to active
    for (std::map<SceneType, bool>::reverse_iterator it = m_scenesActive.rbegin(); it != m_scenesActive.rend(); ++it) {
        if (it->second) {
            m_window.draw(*m_scenes[it->first]);
        }
    }


    // Show the newly drawn objects
    m_window.display();

}

void Engine::input(float elapsedTime) {

    // Iterate forward through the map and find the first active scene, and take input only from that
    // We also update the scene stack based on any inputs
    for (std::map<SceneType, bool>::iterator it = m_scenesActive.begin(); it != m_scenesActive.end(); ++it) {
        if (it->second) {
            updateSceneStack(m_scenes[it->first]->input(m_window, elapsedTime));
            break;
        }
    }

}

void Engine::update(float elapsedTime) {

    // Update every scene (order doesn't really matter, so we'll do it from top down)
    for (std::map<SceneType, bool>::iterator it = m_scenesActive.begin(); it != m_scenesActive.end(); ++it) {
        if (it->second) {
            m_scenes[it->first]->update(m_window, elapsedTime);
        }
    }

}


void Engine::updateSceneStack(std::set<SceneType> activeScenes) {

    // Now iterate through the scenes in the vector
    for (SceneType st: activeScenes) {
        // And toggle them
        m_scenesActive[st] = !m_scenesActive[st];
    }
}

