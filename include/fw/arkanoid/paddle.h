/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_PADDLE_H_
#define FW_ARKANOID_PADDLE_H_

#include "SFML/Graphics.hpp"
#include "fw/arkanoid/dimension.h"
#include "fw/arkanoid/insets.h"
#include "fw/arkanoid/point.h"

namespace fw {
namespace arkanoid {

class Paddle {
 public:
  Paddle(Dimension const kBorders, Point const kPosition)
      : Paddle{kBorders, kPosition, Dimension{kDefaultWidth, kDefaultHeight}} {
  }

  Paddle(Dimension const kBorders, Point const kPosition, Dimension const kSize)
    : kBorders_(kBorders),
      shape_(sf::RectangleShape()),
      velocity_(sf::Vector2f()) {
    this->shape_.setPosition(kPosition.x(), kPosition.y());
    this->shape_.setSize({kSize.width(), kSize.height()});
    this->shape_.setFillColor(sf::Color::Red);
    this->shape_.setOrigin(
        kSize.width() / 2.f,
        kSize.height() / 2.f);
  }

  sf::RectangleShape shape() const noexcept {
    return this->shape_;
  }

  /**
   * Returns the Point of this Paddle.
   *
   * @return The Point.
   */
  Point point() const noexcept {
    return {this->shape_.getPosition().x, this->shape_.getPosition().y};
  }

  /**
   * Returns the Insets of this Paddle.
   *
   * @return The Insets.
   */
  Insets insets() const noexcept {
    float const kTop = this->point().y() - this->shape_.getSize().y / 2.f;
    float const kLeft = this->point().x() - this->shape_.getSize().x / 2.f;
    float const kBottom = this->point().y() + this->shape_.getSize().y / 2.f;
    float const kRight = this->point().x() + this->shape_.getSize().x / 2.f;

    return {kTop, kLeft, kBottom, kRight};
  }

  void update() {
    this->shape_.move(this->velocity_);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->insets().left() > 0) {
      this->velocity_.x = -kDefaultVelocity;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->insets().right() < this->kBorders_.width()) {
      this->velocity_.x = kDefaultVelocity;
    } else {
      this->velocity_.x = 0;
    }
  }

 private:
  static constexpr float kDefaultWidth{60.f};
  static constexpr float kDefaultHeight{20.f};
  static constexpr float kDefaultVelocity{6.f};

  Dimension const kBorders_;
  sf::RectangleShape shape_;

  /** The velocity of this Paddle. */
  sf::Vector2f velocity_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_PADDLE_H_
