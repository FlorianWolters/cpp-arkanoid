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
struct Insets {
  /** The inset from the bottom. */
  float bottom;

  /** The inset from the left. */
  float left;

  /** The inset from the right. */
  float right;

  /** The inset from the top. */
  float top;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_INSETS_H_
