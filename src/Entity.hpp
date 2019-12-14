//
// Created by hugo on 14/12/2019.
//

#ifndef GRAVITYSIMULATOR_ENTITY_HPP
#define GRAVITYSIMULATOR_ENTITY_HPP

#include <utility>

class Entity {
public:
    Entity(int maxMass = 100, std::pair<float, float> maxPosition = std::make_pair(800, 800), std::pair<float, float> maxSpeed = std::make_pair(100, 100));

    const std::pair<float, float> &getPosition() const;

    int getMass() const;

    void setMass(int mass);

    const std::pair<float, float> &getSpeed() const;

    void setSpeed(const std::pair<float, float> &speed);

    void setPosition(const std::pair<float, float> &position);

private:
    int _mass;
    std::pair<float, float> _position;
    std::pair<float, float> _speed;
};


#endif //GRAVITYSIMULATOR_ENTITY_HPP
