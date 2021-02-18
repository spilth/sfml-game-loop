#include <SFML/Graphics.hpp>
#include "DebugPanel.h"

int main() {
    DebugPanel debugInfo;

    sf::Font debugFont;
    debugFont.loadFromFile("fonts/JetBrainsMono-Regular.ttf");

    sf::Clock clock;

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "SFML Game Loop");
//    window.setFramerateLimit(0);
//    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) {
            debugInfo.resetFps();
        }

        sf::Time deltaTime = clock.restart();

        debugInfo.update(deltaTime);

        window.clear();
        debugInfo.draw(window);
        window.display();
    }

    return EXIT_SUCCESS;
}
