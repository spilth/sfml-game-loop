#include <SFML/Graphics.hpp>
#include "DebugPanel.h"

int main() {
    DebugPanel debugInfo;

    sf::Font debugFont;
    debugFont.loadFromFile("fonts/JetBrainsMono-Regular.ttf");

    sf::Event event;
    sf::Clock clock;

    sf::VideoMode vm(1920, 1080);

    sf::RenderWindow window(vm, "SFML Game Loop");
//    window.setFramerateLimit(0);
//    window.setVerticalSyncEnabled(true);

    while (window.isOpen()) {
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

    return 0;
}
