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
    m_titleText.setString("Goon");
    m_titleText.setCharacterSize(120);
    m_titleText.setOrigin(m_titleText.getLocalBounds().width / 2, m_titleText.getLocalBounds().height / 2);
    m_titleText.setPosition(m_windowSize.x / 2, m_windowSize.y * .15f);

    m_playGameText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_playGameText.setString("Play");
    m_playGameText.setCharacterSize(50);
    m_playGameText.setOrigin(m_playGameText.getLocalBounds().width / 2, m_playGameText.getLocalBounds().height / 2);
    m_playGameText.setPosition(m_windowSize.x / 2, m_windowSize.y * .40f);

    m_cardCollectionText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_cardCollectionText.setString("Card Collection");
    m_cardCollectionText.setCharacterSize(50);
    m_cardCollectionText.setOrigin(m_cardCollectionText.getLocalBounds().width / 2, m_cardCollectionText.getLocalBounds().height / 2);
    m_cardCollectionText.setPosition(m_windowSize.x / 2, m_windowSize.y * .50f);

    m_optionsText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_optionsText.setString("Options");
    m_optionsText.setCharacterSize(50);
    m_optionsText.setOrigin(m_optionsText.getLocalBounds().width / 2, m_optionsText.getLocalBounds().height / 2);
    m_optionsText.setPosition(m_windowSize.x / 2, m_windowSize.y * .60f);

    m_exitText.setFont(*ResourceManager::getFont("assets/fonts/vcr_osd.ttf"));
    m_exitText.setString("Exit Game");
    m_exitText.setCharacterSize(50);
    m_exitText.setOrigin(m_exitText.getLocalBounds().width / 2, m_exitText.getLocalBounds().height / 2);
    m_exitText.setPosition(m_windowSize.x / 2, m_windowSize.y * .70f);

}

std::vector<SceneType> MainMenu::input(sf::RenderWindow& window, float elapsedTime) {

    std::vector<SceneType> scenes;
    scenes.push_back(SceneType::MainMenu);

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

    //std::cout << "Drawing main menu" << std::endl;
}