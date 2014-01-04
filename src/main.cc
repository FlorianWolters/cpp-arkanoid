/**
 * COPYRIGHT (C) Florian Wolters 2014
 *
 * @file
 * @author Florian Wolters <wolters.fl@gmail.com>
 */

#include <string>

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"

/**
 * Runs the game *Arkanoid*.
 *
 * @return Always `0`.
 */
int main() {
  constexpr int kWindowWidth{800};
  constexpr int kWindowHeight{600};
  constexpr int kFramerateLimit{60};
  const std::string kApplicationName{"Arkanoid"};

  // Create the game window.
  sf::RenderWindow window{{kWindowWidth, kWindowHeight}, kApplicationName};
  window.setFramerateLimit(kFramerateLimit);

  // Main loop.
  while(true) {
    window.clear(sf::Color::Black);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
      break;
    }

    window.display();
  }

  return 0;
}
