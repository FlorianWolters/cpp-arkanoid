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
struct Dimension {
  /** The width dimension; negative values can be used. */
  float width;

  /** The height dimension; negative values can be used. */
  float height;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_DIMENSION_H_
