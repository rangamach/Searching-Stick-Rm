#include "../../include/Gameplay/GameplayService.h"
#include "../../include/Gameplay/GameplayController.h"
#include "Gameplay/StickCollection/StickCollectionController.h"

namespace Gameplay
{
	void GameplayService::Destroy()
	{
		delete gameplay_controller;
		delete stick_collection_controller;
	}
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
		stick_collection_controller = new StickCollectionController();
	}
	GameplayService::~GameplayService()
	{
		Destroy();
	}
	void GameplayService::Initialize()
	{
		gameplay_controller->Initialize();
		stick_collection_controller->Initialize();
	}
	void GameplayService::Update()
	{
		gameplay_controller->Update();
		stick_collection_controller->Update();
	}
	void GameplayService::Render()
	{
		gameplay_controller->Render();
		stick_collection_controller->Render();
	}
	void GameplayService::Reset()
	{
		gameplay_controller->Reset();
		stick_collection_controller->Reset();
	}
	void GameplayService::SearchElement(StickCollection::SearchType type)
	{
		stick_collection_controller->SearchElement(type);
	}
	StickCollection::SearchType GameplayService::GetCurrentSearchType()
	{
		return stick_collection_controller->GetSearchType();
	}
	int GameplayService::GetNumberOfSticks()
	{
		return stick_collection_controller->GetNumberOfSticks();
	}
}
