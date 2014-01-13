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
   * @param kWidth  The width.
   * @param kHeight The height.
   */
  Dimension(float const kWidth, float const kHeight)
    : kWidth_{kWidth},
      kHeight_{kHeight} {
  }

  /**
   * Returns the width of this Dimension.
   *
   * @return The width.
   */
  float width() const noexcept {
    return this->kWidth_;
  }

  /**
   * Returns the height of this Dimension.
   *
   * @return The height.
   */
  float height() const noexcept {
    return this->kHeight_;
  }

 private:
  /** The width dimension; negative values can be used. */
  float const kWidth_;

  /** The height dimension; negative values can be used. */
  float const kHeight_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_DIMENSION_H_
