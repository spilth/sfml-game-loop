#include "DebugPanel.h"
#include <sstream>
#include <SFML/Graphics.hpp>

DebugPanel::DebugPanel() {
    debugFont.loadFromFile("fonts/JetBrainsMono-Regular.ttf");
    debugText.setFont(debugFont);
    debugText.setPosition(16, 16);
    debugText.setCharacterSize(36);
    debugText.setFillColor(sf::Color::White);
    currentFpsCircle.setRadius(8);
    currentFpsCircle.setFillColor(sf::Color::Yellow);
    currentFpsCircle.setPosition(0, 4);
    lowestFpsCircle.setRadius(8);
    lowestFpsCircle.setFillColor(sf::Color::Red);
    lowestFpsCircle.setPosition(0, 4);
    highestFpsCircle.setRadius(8);
    highestFpsCircle.setFillColor(sf::Color::Green);
    highestFpsCircle.setPosition(0, 4);
}

void DebugPanel::update(sf::Time deltaTime) {
    currentFps = floor(1 / deltaTime.asSeconds());
    if (currentFps > highestFps) highestFps = currentFps;
    if (currentFps < lowestFps) lowestFps = currentFps;

    currentFpsCircle.setPosition((float) currentFps, 4);
    lowestFpsCircle.setPosition((float) lowestFps, 4);
    highestFpsCircle.setPosition((float) highestFps, 4);

    debugStringStream.str("");
    debugStringStream << "FPS: " << currentFps << "\n";
    debugStringStream << "Low/High FPS: " << lowestFps << "/" << highestFps << "\n";
    debugStringStream << "Delta Time: " << deltaTime.asSeconds() << "s\n";
    debugStringStream << "Delete = Reset FPS, ESC = Quit";
    debugText.setString(debugStringStream.str());

}

void DebugPanel::resetFps() {
    lowestFps = 1000;
    highestFps = 0;
}

void DebugPanel::draw(sf::RenderWindow &window) {
    window.draw(debugText);
    window.draw(lowestFpsCircle);
    window.draw(highestFpsCircle);
    window.draw(currentFpsCircle);
}
