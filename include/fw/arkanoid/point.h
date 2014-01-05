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
   * @param x The X coordinate.
   * @param y The Y coordinate.
   */
  Point(float x, float y) : x_{x}, y_{y} {
  }

  /**
   * Returns X coordinate of this Point.
   *
   * @return The X coordinate.
   */
  float x() const noexcept {
    return this->x_;
  }

  /**
   * Returns Y coordinate of this Point.
   *
   * @return The Y coordinate.
   */
  float y() const noexcept {
    return this->y_;
  }

 private:
  /** The X coordinate of this Point. */
  float x_;

  /** The Y coordinate of this Point. */
  float y_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_POINT_H_
