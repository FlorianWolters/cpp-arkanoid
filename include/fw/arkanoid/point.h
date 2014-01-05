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
struct Point {
  /** The X coordinate of this Point. */
  float x;

  /** The Y coordinate of this Point. */
  float y;
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_POINT_H_
