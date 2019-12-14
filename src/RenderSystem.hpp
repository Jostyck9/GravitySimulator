//
// Created by hugo on 14/12/2019.
//

#ifndef GRAVITYSIMULATOR_RENDERSYSTEM_HPP
#define GRAVITYSIMULATOR_RENDERSYSTEM_HPP

#include <list>
#include <SFML/Graphics.hpp>
#include <string>
#include "Entity.hpp"

class RenderSystem {
private:
    sf::RenderWindow _window;
    sf::VertexArray _vertex;

public:
    RenderSystem(size_t nbrEntities);
    ~RenderSystem();

    void createWindow(int width, int length, const std::string &title);
    void createWindowFullScreen(const std::string &title);
    void closeWindow();
    bool isOpen() const;
    void handleEvent();
    void draw(const std::vector<Entity> &entities);

};


#endif //GRAVITYSIMULATOR_RENDERSYSTEM_HPP
