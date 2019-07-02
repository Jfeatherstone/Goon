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

    // Initialize the main menu
    m_mainMenu = new MainMenu();
    m_mainMenu->init(m_windowSize);

    // Enable the main menu since it is the first thing the user should see
    m_sceneStack.push_back(m_mainMenu);
    
    // Initialize the options menu
    m_optionsMenu = new OptionsMenu();
    m_optionsMenu->init(m_windowSize);

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

    // Draw all of the active scenes in "reverse order"
    // which is actually just forward, so the last scene is on top
    for (int i = 0; i < m_sceneStack.size(); i++)
        m_window.draw(*m_sceneStack[i]);


    // Show the newly drawn objects
    m_window.display();

}

void Engine::input(float elapsedTime) {

    // Only take input from the top
    // We then take that input return vector and update our scenestack
    if (m_sceneStack.size() > 0)
        updateSceneStack(m_sceneStack[0]->input(m_window, elapsedTime));

    std::cout << m_sceneStack.size() << std::endl;
}

void Engine::update(float elapsedTime) {

    // Update every scene (order doesn't really matter but we'll do it
    // "backwards" to be consistent with the draw method)
    for (int i = 0; i < m_sceneStack.size(); i++)
        m_sceneStack[i]->update(m_window, elapsedTime);

}


void Engine::updateSceneStack(std::vector<SceneType> activeScenes) {

    // First clear off the active scenes
    m_sceneStack.clear();

    // Now iterate through the scenes
    for (SceneType st: activeScenes) {
        switch (st) {
            case SceneType::MainMenu:
                m_sceneStack.push_back(m_mainMenu);
                break;
            case SceneType::OptionsMenu:
                m_sceneStack.push_back(m_optionsMenu);
                break;
            case SceneType::PauseMenu:
                m_sceneStack.push_back(m_pauseMenu);
                break;
            case SceneType::GameInstance:
                m_sceneStack.push_back(m_gameInstance);
                break;
            case SceneType::CardCollection:
                m_sceneStack.push_back(m_cardCollection);
                break;
        }
    }
}

