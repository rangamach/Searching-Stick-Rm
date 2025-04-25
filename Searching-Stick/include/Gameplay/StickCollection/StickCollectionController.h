#pragma once

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

			void Destroy();

			void InitializeSticks();
			float CalculateStickWidth();
			void UpdateStickPosition();
			void ResetSticksColor();
			void InitializeSticksArray();
			float CalculateStickHeight();
			float CalculateStickHeight(int array_position);

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

		};
	}
}

