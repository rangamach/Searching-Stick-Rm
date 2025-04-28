#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <thread>

namespace Gameplay
{
	namespace StickCollection
	{
		class StickCollectionView;
		class StickCollectionModel;
		enum class SearchType;
		struct Stick;
		class StickCollectionController
		{
		private:
			StickCollectionView* stick_collection_view;
			StickCollectionModel* stick_collection_model;

			std::vector<Stick*> sticks;
			StickCollection::SearchType search_type;
			Stick* stick_to_search;
			int number_of_comparisons;
			int number_of_array_access;
			int current_operation_delay;

			std::thread search_thread;

			sf::String time_complexity;

			void Destroy();

			void InitializeSticks();
			float CalculateStickWidth();
			void UpdateStickPosition();
			void ResetSticksColor();
			void InitializeSticksArray();
			float CalculateStickHeight(int array_position);
			void ShuffleSticks();
			void ResetSearchStick();
			void ResetVariables();

			void ProcessLinearSearch();
			void ProcessSearchThreadState();
			
			void JoinThreads();

		public:
			StickCollectionController();
			~StickCollectionController();

			void Initialize();
			void Update();
			void Render();

			void Reset();
			SearchType GetSearchType();
			int GetNumberOfSticks();
			void SearchElement(SearchType type);
			int GetNumberOfComparisons();
			int GetNumberOfArrayAccess();
			int GetDelayMilliseconds();
			sf::String GetTimeComplexity();

		};
	}
}

