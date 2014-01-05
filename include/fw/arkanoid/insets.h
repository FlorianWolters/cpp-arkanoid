/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_INSETS_H_
#define	FW_ARKANOID_INSETS_H_

namespace fw {
namespace arkanoid {

/**
 * An Insets object is a representation of the borders of a container.
 *
 * It specifies the space that a container must leave at each of its edges. The
 * space can be a border, a blank space, or a title.
 *
 * @author Florian Wolters <wolters.fl@gmail.com>
 */
class Insets {
 public:
  /**
   * Initializes a new instance of the Insets class.
   *
   * @param top    The inset from the top.
   * @param left   The inset from the left.
   * @param bottom The inset from the bottom.
   * @param right  The inset from the right.
   */
  Insets(float top, float left, float bottom, float right)
      : top_{top}, left_{left}, bottom_{bottom}, right_{right} {
  }

  /**
   * Returns the inset from the top.
   *
   * @return The inset from the top.
   */
  float top() const noexcept {
    return this->top_;
  }

  /**
   * Returns the inset from the left.
   *
   * @return The inset from the left.
   */
  float left() const noexcept {
    return this->left_;
  }

  /**
   * Returns the inset from the bottom.
   *
   * @return The inset from the bottom.
   */
  float bottom() const noexcept {
    return this->bottom_;
  }

  /**
   * Returns the inset from the right.
   *
   * @return The inset from the right.
   */
  float right() const noexcept {
    return this->right_;
  }

 private:
  /** The inset from the top. */
  float top_;

  /** The inset from the left. */
  float left_;

  /** The inset from the bottom. */
  float bottom_;

  /** The inset from the right. */
  float right_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_INSETS_H_
