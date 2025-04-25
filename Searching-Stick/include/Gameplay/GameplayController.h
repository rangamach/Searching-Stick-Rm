#pragma once

namespace Gameplay
{
	class GameplayView;
	class GameplayController
	{
	private:
		GameplayView* gameplay_view;

		void Destroy();

	public:
		GameplayController();
		~GameplayController();

		void Initialize();
		void Update();
		void Render();

		void Reset();
	};
}

