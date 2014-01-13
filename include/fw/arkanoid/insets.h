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
   * @param kTop    The inset from the top.
   * @param kLeft   The inset from the left.
   * @param kBottom The inset from the bottom.
   * @param kRight  The inset from the right.
   */
  Insets(float const kTop, float const kLeft, float const kBottom, float const kRight)
      : kTop_{kTop}, kLeft_{kLeft}, kBottom_{kBottom}, kRight_{kRight} {
  }

  /**
   * Returns the inset from the top.
   *
   * @return The inset from the top.
   */
  float top() const noexcept {
    return this->kTop_;
  }

  /**
   * Returns the inset from the left.
   *
   * @return The inset from the left.
   */
  float left() const noexcept {
    return this->kLeft_;
  }

  /**
   * Returns the inset from the bottom.
   *
   * @return The inset from the bottom.
   */
  float bottom() const noexcept {
    return this->kBottom_;
  }

  /**
   * Returns the inset from the right.
   *
   * @return The inset from the right.
   */
  float right() const noexcept {
    return this->kRight_;
  }

  bool IntersectsWith(Insets const &kOther) const noexcept {
    return this->kRight_ >= kOther.kLeft_ && this->kLeft_ <= kOther.kRight_
      && this->kBottom_ >= kOther.kTop_ && this->kTop_ <= kOther.kBottom_;
  }

 private:
  /** The inset from the top. */
  float const kTop_;

  /** The inset from the left. */
  float const kLeft_;

  /** The inset from the bottom. */
  float const kBottom_;

  /** The inset from the right. */
  float const kRight_;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_INSETS_H_
