#include <sstream>
#include <SFML/Graphics.hpp>

int main() {
    std::stringstream debugStringStream;

    sf::Font debugFont;
    debugFont.loadFromFile("fonts/JetBrainsMono-Regular.ttf");

    sf::Event event;
    sf::Clock clock;

    sf::VideoMode vm(1920, 1080);

    sf::RenderWindow window(vm, "SFML Game Loop");
//    window.setFramerateLimit(0);
//    window.setVerticalSyncEnabled(true);

    sf::Text debugText;
    debugText.setFont(debugFont);
    debugText.setPosition(16, 16);
    debugText.setCharacterSize(36);
    debugText.setFillColor(sf::Color::White);

    sf::CircleShape currentFpsCircle(8);
    currentFpsCircle.setFillColor(sf::Color::Yellow);
    currentFpsCircle.setPosition(0, 4);

    sf::CircleShape lowestFpsCircle(8);
    lowestFpsCircle.setFillColor(sf::Color::Red);
    lowestFpsCircle.setPosition(0, 4);

    sf::CircleShape highestFpsCircle(8);
    highestFpsCircle.setFillColor(sf::Color::Green);
    highestFpsCircle.setPosition(0, 4);

    int currentFps;
    int lowestFps = 1000;
    int highestFps = 0;

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
            lowestFps = 1000;
            highestFps = 0;
        }

        sf::Time deltaTime = clock.restart();

        currentFps = floor(1 / deltaTime.asSeconds());
        if (currentFps > highestFps) highestFps = currentFps;
        if (currentFps < lowestFps) lowestFps = currentFps;

        currentFpsCircle.setPosition((float)currentFps, 4);
        lowestFpsCircle.setPosition((float)lowestFps, 4);
        highestFpsCircle.setPosition((float)highestFps, 4);

        debugStringStream.str("");
        debugStringStream << "FPS: " << currentFps << "\n";
        debugStringStream << "Low/High FPS: " << lowestFps << "/" << highestFps << "\n";
        debugStringStream << "Delta Time: " << deltaTime.asSeconds() << "s\n";
        debugStringStream << "Delete = Reset FPS, ESC = Quit";
        debugText.setString(debugStringStream.str());

        window.clear();
        window.draw(debugText);
        window.draw(lowestFpsCircle);
        window.draw(highestFpsCircle);
        window.draw(currentFpsCircle);
        window.display();
    }

    return 0;
}
