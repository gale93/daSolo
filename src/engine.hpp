#pragma once

#include <SFML\Graphics\RenderWindow.hpp>

class Engine
{
	bool isRunning = true;

	sf::RenderWindow window;
public:
	Engine();
	~Engine();

	void start();
	void stop();

	inline sf::RenderWindow& getWindow() { return window; }
};

