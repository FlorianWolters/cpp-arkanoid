/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_BALL_H_
#define FW_ARKANOID_BALL_H_

#include "SFML/Graphics.hpp"
#include "fw/arkanoid/point.h"

namespace fw {
namespace arkanoid {

class Ball {
 public:
  Ball(Point point) : Ball{point, kDefaultRadius_} {
  }

  Ball(Point point, float ballRadius) {
    this->shape_.setPosition(point.x, point.y);
    this->shape_.setRadius(ballRadius);
    this->shape_.setFillColor(sf::Color::Red);
    this->shape_.setOrigin(ballRadius, ballRadius);
  }

  sf::CircleShape shape() const {
    return this->shape_;
  }

  void update() {
    this->shape_.move(this->velocity_);
  }

 private:
  static constexpr float kDefaultRadius_{10.f};
  static constexpr float kDefaultVelocity_{8.f};
  sf::CircleShape shape_;

  /** The velocity of this Ball. */
  sf::Vector2f velocity_{-kDefaultVelocity_, -kDefaultVelocity_};
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_BALL_H_
