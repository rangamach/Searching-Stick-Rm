#include "../../include/Gameplay/GameplayView.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;
	void GameplayView::InitializeBackgroundImage()
	{
		sf::RenderWindow* game_window = ServiceLocator::getInstance()->getGraphicService()->getGameWindow();

		background_image->initialize(Config::background_texture_path, game_window->getSize().x, game_window->getSize().y, sf::Vector2f(0, 0));
		background_image->setImageAlpha(background_image_alpha);
	}
	void GameplayView::Destroy()
	{
		delete background_image;
	}

	GameplayView::GameplayView()
	{
		background_image = new ImageView();
	}

	GameplayView::~GameplayView()
	{
		Destroy();
	}

	void GameplayView::Initialize(GameplayController* controller)
	{
		this->gameplay_controller = controller;
		InitializeBackgroundImage();
	}

	void GameplayView::Update()
	{
		background_image->update();
	}

	void GameplayView::Render()
	{
		background_image->render();
	}
}
