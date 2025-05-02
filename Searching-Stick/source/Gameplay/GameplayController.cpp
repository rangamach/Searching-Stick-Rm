#include "../../include/Gameplay/GameplayController.h"
#include "../../include/Gameplay/GameplayView.h"

namespace Gameplay
{
	void GameplayController::Destroy()
	{
		delete gameplay_view;
	}

	GameplayController::GameplayController()
	{
		gameplay_view = new GameplayView();
	}

	GameplayController::~GameplayController()
	{
		Destroy();
	}

	void GameplayController::Initialize()
	{
		gameplay_view->Initialize(this);
	}

	void GameplayController::Update()
	{
		gameplay_view->Update();
	}

	void GameplayController::Render()
	{
		gameplay_view->Render();
	}

	void GameplayController::Reset()
	{
	}
}
