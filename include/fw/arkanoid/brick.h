/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_BRICK_H_
#define FW_ARKANOID_BRICK_H_

#include <SFML/Graphics.hpp>

#include "fw/arkanoid/dimension.h"
#include "fw/arkanoid/insets.h"
#include "fw/arkanoid/point.h"

namespace fw {
namespace arkanoid {

class Brick {
 public:
  static float constexpr kDefaultWidth{60.f};
  static float constexpr kDefaultHeight{20.f};

  explicit Brick(Point const &kPoint) : shape_{sf::RectangleShape()} {
    this->shape_.setPosition(kPoint.x(), kPoint.y());
    this->shape_.setSize({kDefaultWidth, kDefaultHeight});
    this->shape_.setFillColor(sf::Color::Yellow);
    this->shape_.setOrigin(kDefaultWidth / 2.f, kDefaultHeight / 2.f);
  }

  sf::RectangleShape shape() const noexcept {
    return this->shape_;
  }

  /**
   * Returns the Point of this Brick.
   *
   * @return The Point.
   */
  Point point() const noexcept {
    return {this->shape_.getPosition().x, this->shape_.getPosition().y};
  }
  /**
   * Returns the Insets of this Brick.
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

 private:
  sf::RectangleShape shape_;
  bool is_destroyed_{false};
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_BRICK_H_
