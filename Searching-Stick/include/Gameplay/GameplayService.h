#pragma once

#include <SFML/System/String.hpp>

namespace Gameplay
{
	class GameplayController;
	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;

		void Destroy();

	public:
		GameplayService();
		~GameplayService();

		void Initialize();
		void Update();
		void Render();

		void Reset();
	};
}

