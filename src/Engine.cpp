#include "Engine.hpp"

/************************
 *    STATIC VARIABLES
 ************************/
const sf::Vector2f Engine::DEFAULT_WINDOW_SIZE = sf::Vector2f(800, 600);
const std::string Engine::GAME_NAME = "Goon";

Engine::Engine(sf::Vector2f windowSize) {

    initializeWindow(windowSize);
    initializeAssets();
}

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

void Engine::run() {
    sf::Clock clock;

    while (m_window.isOpen()) {
        sf::Time dt = clock.restart();

        input(dt.asSeconds());

        update(dt.asSeconds());

        draw(dt.asSeconds());
    }
}