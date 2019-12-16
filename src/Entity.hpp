//
// Created by hugo on 14/12/2019.
//

#ifndef GRAVITYSIMULATOR_ENTITY_HPP
#define GRAVITYSIMULATOR_ENTITY_HPP

#include <utility>
#include <SFML/Graphics/Color.hpp>
#include <ostream>

class Entity {
public:
    Entity(int maxMass = 100, std::pair<float, float> maxPosition = std::make_pair(1000, 800), std::pair<float, float> maxSpeed = std::make_pair(0, 0));

    friend std::ostream &operator<<(std::ostream &os, const Entity &entity);

    const std::pair<float, float> &getPosition() const;

    int getMass() const;

    void setMass(int mass);

    const std::pair<float, float> &getSpeed() const;

    void setSpeed(const std::pair<float, float> &speed);

    void setPosition(const std::pair<float, float> &position);

    void attract(Entity &other);

private:
    int _mass;
    std::pair<float, float> _position;
    std::pair<float, float> _speed;
    sf::Color _color;
public:
    const sf::Color &getColor() const;

    void setColor(const sf::Color &color);
};


#endif //GRAVITYSIMULATOR_ENTITY_HPP
