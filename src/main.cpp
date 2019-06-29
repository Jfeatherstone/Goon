#include "Engine.hpp"

int main() {

    sf::Vector2f windowSize(sf::VideoMode::getDesktopMode().width / 1.4f, sf::VideoMode::getDesktopMode().height / 1.4f);

    Engine engine(windowSize);

    engine.run();

    return 0;

}