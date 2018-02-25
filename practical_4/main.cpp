#include <SFML/Graphics.hpp>
#include <string> 
#include <iostream>
#include "Entity.h"
#include "Player.h"
#include "Ghost.h"
#include "pacman.h"
#include "scene.h"
#include "system_renderer.h"

using  namespace  sf;
using  namespace  std;

Player* player;
Ghost* g1;
Ghost* g2;
EntityManager* entityManager;

void  Load() {
	srand(time(NULL));

	// MOVE ENTITY CREATION


	entityManager = new EntityManager();

	entityManager->list.push_back(new Player());
	entityManager->list.push_back(new Ghost());
	entityManager->list.push_back(new Ghost());

	// Load Scene-Local Assets
	gameScene.reset(new GameScene());
	menuScene.reset(new MenuScene());
	gameScene->load();
	menuScene->load();

	// Start ad main menu
	activeScene = menuScene;
}

void  Update(RenderWindow &window) {
	//  Reset  clock , recalculate  deltatime
	static  Clock  clock;
	float  dt = clock.restart().asSeconds ();

	//  check  and  consume  events
	Event  event;

	while (window.pollEvent(event)) {
		if (event.type ==  Event::Closed) {
			window.close();
			return;
		}
	}

	// Quit  Via  ESC  Key
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		window.close();
	}

	entityManager->update(dt);

}

void  Render(RenderWindow &window) {
	
	entityManager->render(window);
	// Now our renderer doesn't render anything. It still rely on the SFML renderer.
	Renderer::render();
}

int  main() {
	
	RenderWindow window(VideoMode(800, 600), "Pacman Game");
	Renderer::initialise(window);

	Load();

	while (window.isOpen()) {
		window.clear();
		Update(window);
		Render(window);
		window.display();
	}
	
	return  0;
}