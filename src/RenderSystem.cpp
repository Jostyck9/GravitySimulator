//
// Created by hugo on 14/12/2019.
//

#include "RenderSystem.hpp"

RenderSystem::RenderSystem() = default;

RenderSystem::~RenderSystem() = default;

void RenderSystem::createWindow(int width, int length, const std::string &title)
{
    _window.create(sf::VideoMode(width, length), title);
}

void RenderSystem::createWindowFullScreen(const std::string &title)
{
    _window.create(sf::VideoMode(100, 100), title, sf::Style::Fullscreen);
}

void RenderSystem::closeWindow()
{
    _window.close();
}

bool RenderSystem::isOpen() const {
    return _window.isOpen();
}

void RenderSystem::handleEvent() {
    sf::Event event;
    while (_window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            closeWindow();
    }
}

void RenderSystem::draw() {
    if (!isOpen())
        return;
    _window.clear();
    //DRAW here
    _window.display();
}
