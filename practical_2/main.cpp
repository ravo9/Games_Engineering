// What is invader, what is sprite here? 21 and 22
// What is the difference between 2 and 3 option in "3.3.1 Runtime Resources Done Right"?

#include  <SFML/Graphics.hpp>
#include <string> 
#include <iostream> 
#include "Ship.h"
#include "game.h"

using  namespace  sf;
using  namespace  std;

Texture spritesheet;
Sprite invader;

vector <Ship *> ships;

void  Load() {

	if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
		cerr << "Failed to load spritesheet!" << endl;
	}
	invader.setTexture(spritesheet);
	invader.setTextureRect(IntRect(0, 0, 32, 32));

	Invader* inv = new Invader(IntRect(0, 0, 32, 32), { 100, 100 });
	ships.push_back(inv);
}

void  Update(RenderWindow &window) {
	//  Reset  clock , recalculate  deltatime
	static  Clock  clock;
	float  dt = clock.restart ().asSeconds ();

	//  check  and  consume  events
	Event  event;

	while (window.pollEvent(event)) {
		if (event.type ==  Event:: Closed) {
			window.close();
			return;
		}
	}

	// Quit  Via  ESC  Key
	if (Keyboard :: isKeyPressed(Keyboard :: Escape)) {
		window.close ();
	}

	// Ships update
	for (auto &s : ships) {
		// Arrow as we want to call a function inside of this object.
		s->Update(dt);
	}

}

void  Render(RenderWindow &window) {
	window.draw(invader);
	// Why is there 'const'?
	for (const auto s : ships) {
		// Star as we want to send this to drawing function.
		window.draw(*s);
	}
}

int  main() {
	RenderWindow  window(VideoMode(gameWidth, gameHeight), "INVADER");

	Load();

	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	
	return  0;
}