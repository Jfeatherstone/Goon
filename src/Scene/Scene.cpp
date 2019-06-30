#include "Scene/Scene.hpp"

const sf::Color Scene::DEFAULT_BACKGROUND_COLOR = sf::Color(50, 50, 50, 255);

Scene::Scene() {

}

void Scene::init(sf::Vector2f windowSize) {
    
}

void Scene::input(float elapsedTime) {

}

void Scene::update(float elapsedTime) {

}

void Scene::draw(sf::RenderTarget& target, sf::RenderStates state) const {

}

sf::RectangleShape Scene::getBackground() {
    return m_background;
}

void Scene::setBackgroundColor(sf::Color backgroundColor) {
    m_backgroundColor = backgroundColor;
}

void Scene::setBackgroundTransparency(float transparency) {
    m_backgroundTransparency = transparency;
    m_background.setFillColor(sf::Color(m_backgroundColor.r, m_backgroundColor.g, m_backgroundColor.b, int(m_backgroundTransparency*255)));
}
