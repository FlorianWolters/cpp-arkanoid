/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_DIMENSION_H_
#define	FW_ARKANOID_DIMENSION_H_

namespace fw {
namespace arkanoid {

/**
 * The Dimension class encapsulates the width and height of a component (in
 * `float` precision) in a single object.
 *
 * @author Florian Wolters <wolters.fl@gmail.com>
 */
class Dimension {
 public:
  /**
   * Initializes a new instance of the Dimension class.
   *
   * @param width  The width.
   * @param height The height.
   */
  Dimension(float width, float height) : width_{width}, height_{height} {
  }

  /**
   * Returns the width of this Dimension.
   *
   * @return The width.
   */
  float width() const noexcept {
    return this->width_;
  }

  /**
   * Returns the height of this Dimension.
   *
   * @return The height.
   */
  float height() const noexcept {
    return this->height_;
  }

 private:
  /** The width dimension; negative values can be used. */
  float width_;

  /** The height dimension; negative values can be used. */
  float height_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_DIMENSION_H_
