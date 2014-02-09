/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#ifndef FW_ARKANOID_GAME_H_
#define FW_ARKANOID_GAME_H_

#include <string>
#include <vector>

#include "SFML/Graphics.hpp"

#include "fw/arkanoid/brick.h"
#include "fw/arkanoid/ball.h"
#include "fw/arkanoid/paddle.h"
#include "fw/arkanoid/dimension.h"

namespace fw {
namespace arkanoid {

/**
 * The class Game encapsulates the application logic for the game "Arkanoid".
 *
 * @author Florian Wolters <wolters.fl@gmail.com>
 */
class Game {
 public:
  /**
   * Initializes a new instance of the Game class.
   */
  Game() {
    this->window_.setFramerateLimit(kFramerateLimit);
  }

  /**
   * Finalizes an instance of the Game class.
   */
  ~Game() {
    this->window_.close();
  }

  Dimension window_size() const noexcept {
    return this->window_size_;
  }

  /**
   * Runs the *Game Loop* of this Game.
   */
  void run() {
    this->is_running_ = true;

    Ball ball{this->window_size_, {kWindowWidth / 2, kWindowHeight / 2}};
    Paddle paddle{this->window_size_, {kWindowWidth / 2, kWindowHeight - 50}};

    std::vector<Brick> bricks;
    constexpr int countBlocksX{11};
    constexpr int countBlocksY{4};

    for (std::size_t i{0}; i < countBlocksX; ++i) {
      for (std::size_t j{0}; j < countBlocksY; ++j) {
        bricks.emplace_back(
            Brick{
                Point{
                    (i + 1) * (Brick::kDefaultWidth + 3) + 22,
                    (j + 2) * (Brick::kDefaultHeight + 3)
                }
            });
      }
    }

    while (this->is_running_) {
      this->window_.clear(sf::Color::Black);
      this->handleInput();

      ball.update();
      paddle.update();

      if (true == this->AreColliding(paddle, ball)) {
        this->UpdateBallVelocity(paddle, ball);
      }
      
      for (auto &brick : bricks) {
        this->testCollision(brick, ball);
      }

      bricks.erase(
          std::remove_if(
              std::begin(bricks),
              std::end(bricks),
              [](Brick const &kBrick) {
                return kBrick.IsDestroyed();
              }),
              std::end(bricks));

      this->window_.draw(ball.shape());
      this->window_.draw(paddle.shape());

      for (auto &brick : bricks) {
        this->window_.draw(brick.shape());
      }

      this->window_.display();
    }
  }

  /**
   * Handles the input for this Game.
   */
  void handleInput() {
    sf::Event event;

    while (this->window_.pollEvent(event)) {
      switch (event.type) {
        case sf::Event::Closed:
          this->is_running_ = false;
          break;
        case sf::Event::KeyPressed:
          if (sf::Keyboard::Escape == event.key.code) {
            this->is_running_ = false;
          }
          break;
        default:
          break;
      }
    }
  }

  // TODO Refactor the following methods.

  bool AreColliding(Paddle const &kPaddle, Ball const &kBall) const noexcept {
    return kPaddle.insets().IntersectsWith(kBall.insets());
  }

  void UpdateBallVelocity(Paddle const &kPaddle, Ball &ball) const {
    ball.UpdateVelocity(
      this->CalculateBallVelocityForX(kPaddle, ball),
      -Ball::kDefaultVelocity_);
  }

  float CalculateBallVelocityForX(Paddle const &kPaddle, Ball const &kBall) const noexcept {
    return (kBall.point().x() < kPaddle.point().x())
      ? -Ball::kDefaultVelocity_
      : Ball::kDefaultVelocity_;
  }

  void testCollision(Brick &brick, Ball &ball) const {
    if (false == brick.insets().IntersectsWith(ball.insets())) {
      return;
    }

    brick.Destroy();
    Dimension const kMinimumOverlap = this->CalculateMinimumOverlap(
        ball.insets(),
        brick.insets());

    if (abs(kMinimumOverlap.width()) < abs(kMinimumOverlap.height())) {
      ball.UpdateVelocity(
        (this->CollidesBallWithLeft(ball.insets(), brick.insets()) ? -Ball::kDefaultVelocity_ : Ball::kDefaultVelocity_),
        ball.velocity().y);
    } else {
      ball.UpdateVelocity(
        ball.velocity().x,
        (this->CollidesBallWithTop(ball.insets(), brick.insets()) ? -Ball::kDefaultVelocity_ : Ball::kDefaultVelocity_));
    }
  }

  bool CollidesBallWithLeft(Insets const &mBall, Insets const &mBrick) const noexcept {
    float const overlapLeft{mBall.right() - mBrick.left()};
    float const overlapRight{mBrick.right() - mBall.left()};

    return abs(overlapLeft) < abs(overlapRight);
  }

  bool CollidesBallWithTop(Insets const &mBall, Insets const &mBrick) const noexcept {
    float const overlapTop{mBall.bottom() - mBrick.top()};
    float const overlapBottom{mBrick.bottom() - mBall.top()};

    return abs(overlapTop) < abs(overlapBottom);
  }

  Dimension CalculateMinimumOverlap(Insets const &mBall, Insets const &mBrick) const noexcept {
    float overlapLeft{mBall.right() - mBrick.left()};
    float overlapRight{mBrick.right() - mBall.left()};
    float overlapTop{mBall.bottom() - mBrick.top()};
    float overlapBottom{mBrick.bottom() - mBall.top()};
    bool ballFromLeft(abs(overlapLeft) < abs(overlapRight));
    bool ballFromTop(abs(overlapTop) < abs(overlapBottom));
    float minOverlapX{ballFromLeft ? overlapLeft : overlapRight};
    float minOverlapY{ballFromTop ? overlapTop : overlapBottom};

    return {minOverlapX, minOverlapY};
  }


 private:
  /** The width of the window of this Game in pixels. */
  static constexpr int kWindowWidth{800};

  /** The height of the window of this Game in pixels. */
  static constexpr int kWindowHeight{600};

  /** The maximum framerate for this Game. */
  static constexpr int kFramerateLimit{60};

  /** The name of this Game. */
  const std::string kApplicationName{"Arkanoid"};

  /** Whether this Game is running. */
  bool is_running_{false};

  Dimension window_size_{kWindowWidth, kWindowHeight};

  /** The window of this Game. */
  sf::RenderWindow window_{{kWindowWidth, kWindowHeight}, kApplicationName};
};

} // namespace arkanoid
} // namespace fw

#endif  // FW_ARKANOID_GAME_H_
