/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#include "fw/arkanoid/game.h"

/**
 * Runs the game *Arkanoid*.
 *
 * @return Always `0`.
 */
int main() {
  fw::arkanoid::Game{}.run();

  return 0;
}
