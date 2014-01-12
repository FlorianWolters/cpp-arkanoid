/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_BALL_H_
#define FW_ARKANOID_BALL_H_

#include "SFML/Graphics.hpp"
#include "fw/arkanoid/dimension.h"
#include "fw/arkanoid/insets.h"
#include "fw/arkanoid/point.h"
#include "dimension.h"

namespace fw {
namespace arkanoid {

class Ball {
 public:
  Ball(Dimension borders, Point position)
      : Ball{borders, position, kDefaultRadius_} {
  }

  Ball(Dimension borders, Point position, float ballRadius)
      : borders_(borders), shape_(sf::CircleShape()) {
    this->shape_.setPosition(position.x(), position.y());
    this->shape_.setRadius(ballRadius);
    this->shape_.setFillColor(sf::Color::Red);
    this->shape_.setOrigin(ballRadius, ballRadius);
  }

  sf::CircleShape shape() const {
    return this->shape_;
  }

  /**
   * Returns the Point of this Ball.
   *
   * @return The Point.
   */
  Point point() const noexcept {
    return {this->shape_.getPosition().x, this->shape_.getPosition().y};
  }

  /**
   * Returns the Insets of this Ball.
   *
   * @return The Insets.
   */
  Insets insets() const noexcept {
    const float kLeft = this->point().x() - this->shape_.getRadius();
    const float kRight = this->point().x() + this->shape_.getRadius();
    const float kTop = this->point().y() - this->shape_.getRadius();
    const float kBottom = this->point().y() + this->shape_.getRadius();

    return {kTop, kLeft, kBottom, kRight};
  }

  void update() {
    if (this->insets().left() < 0) {
      this->velocity_.x = kDefaultVelocity_;
    } else if (this->insets().right() > this->borders_.width()) {
      this->velocity_.x = -kDefaultVelocity_;
    }

    if (this->insets().top() < 0) {
      this->velocity_.y = kDefaultVelocity_;
    } else if(this->insets().bottom() > this->borders_.height()) {
      this->velocity_.y = -kDefaultVelocity_;
    }

    this->shape_.move(this->velocity_);
  }

 private:
  static constexpr float kDefaultRadius_{10.f};
  static constexpr float kDefaultVelocity_{8.f};

  Dimension borders_;
  sf::CircleShape shape_;

  /** The velocity of this Ball. */
  sf::Vector2f velocity_{-kDefaultVelocity_, -kDefaultVelocity_};
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_BALL_H_
