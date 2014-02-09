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
#include "fw/arkanoid/rectangle_base.h"

namespace fw {
namespace arkanoid {

class Paddle : public RectangleBase {
 public:
  Paddle(Dimension const kBorders, Point const kPosition)
      : Paddle{kBorders, kPosition, Dimension{kDefaultWidth, kDefaultHeight}} {
  }

  Paddle(Dimension const kBorders, Point const kPosition, Dimension const kSize)
    : kBorders_(kBorders),
      velocity_(sf::Vector2f()) {
    this->shape().setPosition(kPosition.x(), kPosition.y());
    this->shape().setSize({kSize.width(), kSize.height()});
    this->shape().setFillColor(sf::Color::Red);
    this->shape().setOrigin(
        kSize.width() / 2.f,
        kSize.height() / 2.f);
  }

  void update() {
    this->shape().move(this->velocity_);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && this->insets().left() > 0) {
      this->velocity_.x = -kDefaultVelocity;
    } else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && this->insets().right() < this->kBorders_.width()) {
      this->velocity_.x = kDefaultVelocity;
    } else {
      this->velocity_.x = 0;
    }
  }

 private:
  static float constexpr kDefaultWidth{60.f};
  static float constexpr kDefaultHeight{20.f};
  static float constexpr kDefaultVelocity{6.f};

  Dimension const kBorders_;

  /** The velocity of this Paddle. */
  sf::Vector2f velocity_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_PADDLE_H_
