#pragma once

#include <SFML/System/String.hpp>
#include "Gameplay/StickCollection/StickCollectionController.h"

namespace Gameplay
{
	using namespace StickCollection;
	class GameplayController;
	enum class SearchType;
	class GameplayService
	{
	private:
		GameplayController* gameplay_controller;
		StickCollectionController* stick_collection_controller;

		void Destroy();

	public:
		GameplayService();
		~GameplayService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void SearchElement(StickCollection::SearchType type);
		StickCollection::SearchType GetCurrentSearchType();
		int GetNumberOfSticks();
	};
}

