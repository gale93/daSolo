#pragma once

class Engine
{
	bool isRunning = true;

public:
	Engine();
	~Engine();

	void start();
	void stop();
};

