/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_BALL_H_
#define FW_ARKANOID_BALL_H_

#include "SFML/Graphics.hpp"

namespace fw {
namespace arkanoid {

class Ball {
 public:
  Ball(float x, float y) : Ball{x, y, kDefaultBallRadius_} {
  }

  Ball(float x, float y, float ballRadius) {
    this->shape_.setPosition(x, y);
    this->shape_.setRadius(ballRadius);
    this->shape_.setFillColor(sf::Color::Red);
    this->shape_.setOrigin(ballRadius, ballRadius);
  }

  sf::CircleShape shape() const {
    return this->shape_;
  }

 private:
  static constexpr float kDefaultBallRadius_{10.f};
  sf::CircleShape shape_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_BALL_H_
