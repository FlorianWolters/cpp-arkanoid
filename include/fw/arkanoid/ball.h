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

namespace fw {
namespace arkanoid {

class Ball {
 public:
  static constexpr float kDefaultVelocity_{8.f};

  Ball(Dimension const kBorders, Point const kPosition)
      : Ball{kBorders, kPosition, kDefaultRadius_} {
  }

  Ball(Dimension const kBorders, Point const kPosition, float const kBallRadius)
      : kBorders_(kBorders), shape_(sf::CircleShape()) {
    this->shape_.setPosition(kPosition.x(), kPosition.y());
    this->shape_.setRadius(kBallRadius);
    this->shape_.setFillColor(sf::Color::Red);
    this->shape_.setOrigin(kBallRadius, kBallRadius);
  }

  sf::CircleShape shape() const noexcept {
    return this->shape_;
  }

  sf::Vector2f velocity() const noexcept {
    return this->velocity_;
  }

  void UpdateVelocity(float const kX, float const kY) {
    this->velocity_.x = kX;
    this->velocity_.y = kY;
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
    float const kTop = this->point().y() - this->shape_.getRadius();
    float const kLeft = this->point().x() - this->shape_.getRadius();
    float const kBottom = this->point().y() + this->shape_.getRadius();
    float const kRight = this->point().x() + this->shape_.getRadius();

    return {kTop, kLeft, kBottom, kRight};
  }

  void update() {
    if (this->insets().left() < 0) {
      this->velocity_.x = kDefaultVelocity_;
    } else if (this->insets().right() > this->kBorders_.width()) {
      this->velocity_.x = -kDefaultVelocity_;
    }

    if (this->insets().top() < 0) {
      this->velocity_.y = kDefaultVelocity_;
    } else if(this->insets().bottom() > this->kBorders_.height()) {
      this->velocity_.y = -kDefaultVelocity_;
    }

    this->shape_.move(this->velocity_);
  }

 private:
  static constexpr float kDefaultRadius_{10.f};

  Dimension const kBorders_;
  sf::CircleShape shape_;

  /** The velocity of this Ball. */
  sf::Vector2f velocity_{-kDefaultVelocity_, -kDefaultVelocity_};
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_BALL_H_
