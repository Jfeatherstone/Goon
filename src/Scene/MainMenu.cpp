#include "Scene/MainMenu.hpp"

const sf::Color MainMenu::DEFAULT_TEXT_COLOR = sf::Color(10, 10, 10);
const sf::Color MainMenu::HIGHLIGHT_TEXT_COLOR = sf::Color(200, 200, 200);


MainMenu::MainMenu() {

}

void MainMenu::init(sf::Vector2f windowSize) {

    m_windowSize = windowSize;

    setBackgroundTransparency(1.0f);

    m_background.setFillColor(DEFAULT_BACKGROUND_COLOR);
    m_background.setSize(m_windowSize);

    m_titleText.setFont(*ResourceManager::getFont("assets/fonts/KarmaFuture.ttf"));
    m_titleText.setString(Engine::GAME_NAME);
    m_titleText.setCharacterSize(m_windowSize.x * .12f);
    m_titleText.setOrigin(m_titleText.getLocalBounds().width / 2, m_titleText.getLocalBounds().height / 2);
    m_titleText.setPosition(m_windowSize.x / 2, m_windowSize.y * .15f);

    m_playGameText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_playGameText.setString("Play");
    m_playGameText.setCharacterSize(m_windowSize.x * .05f);
    m_playGameText.setOrigin(m_playGameText.getLocalBounds().width / 2, m_playGameText.getLocalBounds().height / 2);
    m_playGameText.setPosition(m_windowSize.x / 2, m_windowSize.y * .40f);

    m_cardCollectionText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_cardCollectionText.setString("Card Collection");
    m_cardCollectionText.setCharacterSize(m_windowSize.x * .05f);
    m_cardCollectionText.setOrigin(m_cardCollectionText.getLocalBounds().width / 2, m_cardCollectionText.getLocalBounds().height / 2);
    m_cardCollectionText.setPosition(m_windowSize.x / 2, m_windowSize.y * .50f);

    m_optionsText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_optionsText.setString("Options");
    m_optionsText.setCharacterSize(m_windowSize.x * .05f);
    m_optionsText.setOrigin(m_optionsText.getLocalBounds().width / 2, m_optionsText.getLocalBounds().height / 2);
    m_optionsText.setPosition(m_windowSize.x / 2, m_windowSize.y * .60f);

    m_exitText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_exitText.setString("Exit Game");
    m_exitText.setCharacterSize(m_windowSize.x * .05f);
    m_exitText.setOrigin(m_exitText.getLocalBounds().width / 2, m_exitText.getLocalBounds().height / 2);
    m_exitText.setPosition(m_windowSize.x / 2, m_windowSize.y * .70f);

    m_versionText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    std::stringstream versionText;
    versionText << "Version " << Engine::VERSION;
    m_versionText.setString(versionText.str());
    m_versionText.setCharacterSize(m_windowSize.x * .02f);
    // We don't center this text box as we want it in the bottom left corner
    m_versionText.setPosition(0, m_windowSize.y * .97f);

}

std::set<SceneType> MainMenu::input(sf::RenderWindow& window, float elapsedTime) {

    std::set<SceneType> scenes;

    // We take the relative mouse position so we can highlight any text options that the mouse is inside of
    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

    // The play game option
    if (m_playGameText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        m_playGameText.setFillColor(HIGHLIGHT_TEXT_COLOR);
    else
        m_playGameText.setFillColor(DEFAULT_TEXT_COLOR);

    // The card collection option
    if (m_cardCollectionText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        m_cardCollectionText.setFillColor(HIGHLIGHT_TEXT_COLOR);
    else
        m_cardCollectionText.setFillColor(DEFAULT_TEXT_COLOR);

    // The options option
    if (m_optionsText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        m_optionsText.setFillColor(HIGHLIGHT_TEXT_COLOR);
    else
        m_optionsText.setFillColor(DEFAULT_TEXT_COLOR);

    // The exit game option
    if (m_exitText.getGlobalBounds().contains(mousePosition.x, mousePosition.y))
        m_exitText.setFillColor(HIGHLIGHT_TEXT_COLOR);
    else
        m_exitText.setFillColor(DEFAULT_TEXT_COLOR);

    // And check for key presses and mouse clicks using events
    sf::Event event;
    while (window.pollEvent(event)) {

        if (event.type == sf::Event::KeyPressed) {

            // Open the option menu on esc
            if (event.key.code == sf::Keyboard::Escape)
                scenes.insert(SceneType::OptionsMenu);

        }

        if (event.type == sf::Event::MouseButtonPressed) {

            // The play game option
            if (m_playGameText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                
            }

            // The card collection option
            if (m_cardCollectionText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {

            }

            // The options option
            if (m_optionsText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // Put the options scene on top of the main menu
                scenes.insert(SceneType::OptionsMenu);
            }

            // The exit game option
            if (m_exitText.getGlobalBounds().contains(mousePosition.x, mousePosition.y)) {
                // TODO: Put any closing and saving stuff here
                exit(0);
            }

        }
    }

        return scenes;

}

void MainMenu::update(sf::RenderWindow& window, float elapsedTime) {


}

void MainMenu::draw(sf::RenderTarget& target, sf::RenderStates state) const {

    // First we draw the background
    target.draw(m_background);

    target.draw(m_titleText);
    target.draw(m_playGameText);
    target.draw(m_cardCollectionText);
    target.draw(m_optionsText);
    target.draw(m_exitText);
    target.draw(m_versionText);

    //std::cout << "Drawing main menu" << std::endl;
}