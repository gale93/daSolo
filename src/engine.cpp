#include "engine.hpp"

#include <ctime>
#include <chrono>

#define UPDATES_PER_SEC 60
#define TIMESTEP_N 1000000000 / UPDATES_PER_SEC
#define TIMESTEP_S 1.f / UPDATES_PER_SEC


Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::stop() { isRunning = false; }

void Engine::start()
{
	using clock = std::chrono::high_resolution_clock;
	constexpr std::chrono::nanoseconds timestep(TIMESTEP_N);

	std::chrono::nanoseconds acc(0);
	auto time_start = clock::now();

	while (isRunning)
	{
		auto delta_time = clock::now() - time_start;
		time_start = clock::now();
		acc += std::chrono::duration_cast<std::chrono::nanoseconds>(delta_time);

		// free update
		while (acc >= timestep)
		{
			acc -= timestep;
			// fixed update
		}

		const auto alpha = (float)acc.count() / timestep.count();
		// render
	}
}

int main(int argc, char* argv[])
{
	std::srand(std::time(nullptr));
	Engine engine;

	engine.start();

	return 0;
}