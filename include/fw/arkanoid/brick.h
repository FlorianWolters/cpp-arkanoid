/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_BRICK_H_
#define FW_ARKANOID_BRICK_H_

#include "fw/arkanoid/dimension.h"
#include "fw/arkanoid/rectangle_base.h"

namespace fw {
namespace arkanoid {

class Brick : public RectangleBase {
 public:
  static float constexpr kDefaultWidth{60.f};
  static float constexpr kDefaultHeight{20.f};

  explicit Brick(Point const kPosition) {
    this->shape().setPosition(kPosition.x(), kPosition.y());
    this->shape().setSize({kDefaultWidth, kDefaultHeight});
    this->shape().setFillColor(sf::Color::Yellow);
    this->shape().setOrigin(kDefaultWidth / 2.f, kDefaultHeight / 2.f);
  }

  bool IsDestroyed() const noexcept {
    return this->is_destroyed_;
  }

  void Destroy() noexcept {
    this->is_destroyed_ = true;
  }

 private:
  bool is_destroyed_{false};
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_BRICK_H_
