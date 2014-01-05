/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#include <string>

#include "SFML/Graphics.hpp"

class Game {
 public:
  Game() {
    this->window_.setFramerateLimit(kFramerateLimit);
  }

  ~Game() {
    this->window_.close();
   }

  /**
   * Runs the loop (called *Game Loop*) of this Game
   */
  void run() {
    this->is_running_ = true;

    while(this->is_running_) {
      this->window_.clear(sf::Color::Black);
      this->handleInput();
      this->window_.display();
    }
  }

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

  private:
   static constexpr int kWindowWidth{800};
   static constexpr int kWindowHeight{600};
   static constexpr int kFramerateLimit{60};
   const std::string kApplicationName{"Arkanoid"};
 
   bool is_running_{false};
   sf::RenderWindow window_{{kWindowWidth, kWindowHeight}, kApplicationName};
};

/**
 * Runs the game *Arkanoid*.
 *
 * @return Always `0`.
 */
int main() {
  Game{}.run();

  return 0;
}
