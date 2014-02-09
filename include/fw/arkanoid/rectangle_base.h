/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_RECTANGLEBASE_H_
#define FW_ARKANOID_RECTANGLEBASE_H_

#include "SFML/Graphics.hpp"

#include "fw/arkanoid/insets.h"
#include "fw/arkanoid/point.h"

namespace fw {
namespace arkanoid {

class RectangleBase {
 public:
  RectangleBase() : shape_(sf::RectangleShape()) {
  }
  
  virtual ~RectangleBase() {
  }

  /**
   * Returns the shape of this Rectangle.
   *
   * @return The shape.
   */
  sf::RectangleShape& shape() noexcept {
    return this->shape_;
  }

  /**
   * Returns the Point of this Rectangle.
   *
   * @return The Point.
   */
  Point point() const noexcept {
    return {this->shape_.getPosition().x, this->shape_.getPosition().y};
  }

  /**
   * Returns the Insets of this Rectangle.
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
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_RECTANGLEBASE_H_
