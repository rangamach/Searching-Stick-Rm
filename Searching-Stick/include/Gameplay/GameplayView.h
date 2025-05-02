#pragma once

#include <SFML/Graphics.hpp>
#include "UI/UIElement/ImageView.h"

namespace Gameplay
{
	class GameplayController;
	class GameplayView
	{
	private:
		GameplayController* gameplay_controller;
		UI::UIElement::ImageView* background_image;
		const float background_image_alpha = 55.f;
		sf::Font font;

		void InitializeBackgroundImage();
		void Destroy();

	public:
		GameplayView();
		~GameplayView();

		void Initialize(GameplayController* controller);
		void Update();
		void Render();
	};
}

