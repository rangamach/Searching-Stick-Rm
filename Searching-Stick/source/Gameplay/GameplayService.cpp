#include "../../include/Gameplay/GameplayService.h"
#include "../../include/Gameplay/GameplayController.h"

namespace Gameplay
{
	void GameplayService::Destroy()
	{
		delete gameplay_controller;
	}
	GameplayService::GameplayService()
	{
		gameplay_controller = new GameplayController();
	}
	GameplayService::~GameplayService()
	{
		Destroy();
	}
	void GameplayService::Initialize()
	{
		gameplay_controller->Initialize();
	}
	void GameplayService::Update()
	{
		gameplay_controller->Update();
	}
	void GameplayService::Render()
	{
		gameplay_controller->Render();
	}
	void GameplayService::Reset()
	{
		gameplay_controller->Reset();
	}
}
