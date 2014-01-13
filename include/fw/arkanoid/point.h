/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_POINT_H_
#define	FW_ARKANOID_POINT_H_

namespace fw {
namespace arkanoid {

/**
 * A Point representing a location in `(x,y)` coordinate space, specified in
 * `float` precision.
 *
 * @author Florian Wolters <wolters.fl@gmail.com>
 */
class Point {
 public:
  /**
   * Initializes a new instance of the Point class.
   *
   * @param kX The X coordinate.
   * @param kY The Y coordinate.
   */
  Point(float const kX, float const kY) : kX_{kX}, kY_{kY} {
  }

  /**
   * Returns X coordinate of this Point.
   *
   * @return The X coordinate.
   */
  float x() const noexcept {
    return this->kX_;
  }

  /**
   * Returns Y coordinate of this Point.
   *
   * @return The Y coordinate.
   */
  float y() const noexcept {
    return this->kY_;
  }

 private:
  /** The X coordinate of this Point. */
  float const kX_;

  /** The Y coordinate of this Point. */
  float const kY_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_POINT_H_
