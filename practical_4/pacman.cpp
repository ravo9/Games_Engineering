#include "pacman.h"
#include "Player.h"
#include "Ghost.h"
#include "system_renderer.h"

using  namespace  sf;

// Externs are defined here
std::shared_ptr<Scene> gameScene;
std::shared_ptr<Scene> menuScene;
std::shared_ptr<Scene> activeScene;

void MenuScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Space)) {
		activeScene = gameScene;
	}
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
}

void MenuScene::load() {
	
}

void GameScene::respawn() {

}

void GameScene::update(double dt) {
	if (Keyboard::isKeyPressed(Keyboard::Tab)) {
		activeScene = menuScene;
	}
	Scene::update(dt);
	// ...
}

void GameScene::render() {
	
}

void GameScene::load() {

	_ents = new EntityManager();
	_ents->list.push_back(new Player());
	_ents->list.push_back(new Ghost());
	_ents->list.push_back(new Ghost());
}




