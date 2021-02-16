#ifndef GAMELOOP_DEBUGPANEL_H
#define GAMELOOP_DEBUGPANEL_H

#include <sstream>
#include <SFML/Graphics.hpp>

class DebugPanel {
    std::stringstream debugStringStream;

    int currentFps = 0;
    int lowestFps = 1000;
    int highestFps = 0;

    sf::Font debugFont;
    sf::Text debugText;
    sf::CircleShape currentFpsCircle;
    sf::CircleShape lowestFpsCircle;
    sf::CircleShape highestFpsCircle;

public:
    DebugPanel();

    void update(sf::Time deltaTime);

    void resetFps();

    void draw(sf::RenderWindow &window);
};

#endif
