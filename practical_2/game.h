#pragma once
#include <SFML/Graphics.hpp>

constexpr uint16_t gameWidth = 800;
constexpr uint16_t gameHeight = 600;
constexpr uint16_t invaders_rows = 5;
constexpr uint16_t invaders_columns = 12;

const  sf::Keyboard::Key  controls[2] = {
	sf::Keyboard::Left,
	sf::Keyboard::Right,
};

extern sf::Texture spritesheet;
extern std::vector <Ship *> ships;