#pragma once

#include <SFML\Graphics\RenderWindow.hpp>
#include "scenemanager.hpp"

class Engine
{
	bool isRunning = true;

	sf::RenderWindow window;
	SceneManager sceneMng;
public:
	Engine();
	~Engine();

	void start();
	void stop();

	inline sf::RenderWindow& getWindow() { return window; }
	inline SceneManager& getSceneManager() { return sceneMng; }
};

