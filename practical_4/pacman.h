#include <iostream>
#include "scene.h"

extern std::shared_ptr<Scene> gameScene;
extern std::shared_ptr<Scene> menuScene;
extern std::shared_ptr<Scene> activeScene;

class MenuScene : public Scene {
private:
	sf::Text text;
	sf::Font font;

public:
	// Is it correct?
	MenuScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
};

class GameScene : public Scene {
private:
	sf::Text text;
	sf::Clock scoreClock;
	void respawn();

public:
	GameScene() = default;
	void update(double dt) override;
	void render() override;
	void load() override;
};