#include "Gameplay/StickCollection/StickCollectionController.h"
#include "Gameplay/StickCollection/StickCollectionModel.h"

namespace Gameplay
{
	namespace StickCollection
	{
		void StickCollectionController::Destroy()
		{
			delete stick_collection_model;
		}
		void StickCollectionController::InitializeSticks()
		{
		}
		float StickCollectionController::CalculateStickWidth()
		{
			return 0.0f;
		}
		void StickCollectionController::UpdateStickPosition()
		{
		}
		void StickCollectionController::ResetSticksColor()
		{
		}
		void StickCollectionController::InitializeSticksArray()
		{
		}
		float StickCollectionController::CalculateStickHeight()
		{
			return 0.0f;
		}
		float StickCollectionController::CalculateStickHeight(int array_position)
		{
			return 0.0f;
		}
		StickCollectionController::StickCollectionController()
		{
			stick_collection_model = new StickCollectionModel();
		}
		StickCollectionController::~StickCollectionController()
		{
			Destroy();
		}
		void StickCollectionController::Initialize()
		{
		}
		void StickCollectionController::Update()
		{
		}
		void StickCollectionController::Render()
		{
		}
		void StickCollectionController::Reset()
		{
		}
		SearchType StickCollectionController::GetSearchType()
		{
			return search_type;
		}
		int StickCollectionController::GetNumberOfSticks()
		{
			return stick_collection_model->number_of_sticks;
		}
		void StickCollectionController::SearchElement(SearchType type)
		{
			
		}
	}
}
