#pragma once

#include <SFML\Graphics\RenderWindow.hpp>
#include <SFML\Window\Event.hpp>
#include "scenemanager.hpp"
#include "texturemanager.hpp"

class Engine
{
	bool isRunning = true;

	sf::RenderWindow window;
	SceneManager sceneMng;
	TextureManager textureMng;
public:
	Engine();
	~Engine();

	void start();
	void stop();

	inline sf::RenderWindow& getWindow() { return window; }
	inline SceneManager& getSceneManager() { return sceneMng; }
	inline TextureManager& getTextureManager() { return textureMng; }
};

