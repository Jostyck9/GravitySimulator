//
// Created by hugo on 14/12/2019.
//

#include "RenderSystem.hpp"

RenderSystem::RenderSystem(size_t nbrEntities) : _vertex(sf::Points, nbrEntities)
{
}

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

void RenderSystem::draw(const std::vector<Entity> &entities) {
    if (!isOpen())
        return;
    _window.clear();

    size_t i = 0;
    for (const auto &item : entities) {
        if (i >= _vertex.getVertexCount())
            break;
        _vertex[i].position = sf::Vector2f(item.getPosition().first, item.getPosition().second);
        _vertex[i].color = item.getColor();
        i++;
    }
    _window.draw(_vertex);
    _window.display();
}
