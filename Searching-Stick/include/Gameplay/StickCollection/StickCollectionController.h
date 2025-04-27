#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

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

		};
	}
}

