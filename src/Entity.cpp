//
// Created by hugo on 14/12/2019.
//

#include <random>
#include <iostream>
#include "Entity.hpp"

Entity::Entity(int maxMass, std::pair<float, float> maxPosition, std::pair<float, float> maxSpeed) :
                _mass(rand() % maxMass),
                _position(rand() % static_cast<int>(maxPosition.first), rand() % static_cast<int>(maxPosition.second)),
                _speed(rand() % static_cast<int>((maxSpeed.first) == 0) ? 1 : maxSpeed.first, rand() % static_cast<int>((maxSpeed.second) == 0) ? 1 : maxSpeed.second) {

    static size_t i = 0;

    switch (i) {
        case 0:
            _color = sf::Color::Red;
            break;
        case 1:
            _color = sf::Color::Blue;
            break;
        case 2:
            _color = sf::Color::Green;
            break;
        default:
            _color = sf::Color::Green;
            break;
    }
    i++;
    if (i >= 3)
        i = 0;
    if (rand() % 2 == 0) {
        _speed.first *= -1;
    }
    if (rand() % 2 == 0) {
        _speed.second *= -1;
    }
}

const std::pair<float, float> &Entity::getPosition() const {
    return _position;
}

void Entity::setPosition(const std::pair<float, float> &position) {
    _position = position;
}

int Entity::getMass() const {
    return _mass;
}

void Entity::setMass(int mass) {
    _mass = mass;
}

const std::pair<float, float> &Entity::getSpeed() const {
    return _speed;
}

void Entity::setSpeed(const std::pair<float, float> &speed) {
    _speed = speed;
}

const sf::Color &Entity::getColor() const {
    return _color;
}

void Entity::setColor(const sf::Color &color) {
    _color = color;
}

std::ostream &operator<<(std::ostream &os, const Entity &entity) {
    os << "_position: " << entity._position.first << " " << entity._position.second;
    return os;
}

void Entity::attract(Entity &other) {
    std::pair<float, float> direction;
    float force = 0;
    float g = 6.67430 * std::pow(10, -7);
    float distance = 0;

    direction.first = (other.getPosition().first - _position.first);
    direction.second = (other.getPosition().second - _position.second);

    distance = std::sqrt(std::pow(direction.first, 2) + std::pow(direction.second, 2));

    if (direction.first != 0)
        direction.first = direction.first / std::abs(direction.first);
    if (direction.second != 0)
        direction.second = direction.second / std::abs(direction.second);

    force = (g) * (_mass * other.getMass()) / distance;
    _speed.first += direction.first * force;
    _speed.second += direction.second * force;
    other.setSpeed(std::make_pair(other.getSpeed().first + (direction.first * force * -1), other.getSpeed().second + (direction.second * force * -1)));
}
