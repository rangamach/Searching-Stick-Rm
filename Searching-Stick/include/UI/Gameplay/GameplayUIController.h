#pragma once

#include "UI/Interface/IUIController.h"
#include "UI/UIElement/TextView.h";
#include "UI/UIElement/ButtonView.h"
#include "Gameplay/GameplayService.h"

namespace UI
{
	namespace GameplayUI
	{
		class GameplayUIController : public Interface::IUIController
		{
		private:
			UIElement::TextView* search_type_text;
			UIElement::TextView* number_of_comparisons_text;
			UIElement::TextView* number_of_array_access_text;
			UIElement::TextView* number_of_sticks_text;
			UIElement::TextView* delay_text;
			UIElement::TextView* time_complexity_text;

			UIElement::ButtonView* menu_button;

			Gameplay::SearchType current_search_type;

			const float font_size = 40.f;
			const float text_y_pos = 36.f;
			const float text_y_pos2 = 76.f;
			const float search_type_text_x_pos = 60.f;
			const float comparisons_text_x_pos = 687.f;
			const float array_access_text_x_pos = 1250.f;
			const float number_of_sticks_text_x_pos = 60.f;
			const float delay_text_x_pos = 687.f;
			const float time_complexity_text_x_pos = 1250.f;
			const float menu_button_x_pos = 1770.f;
			const float menu_button_y_pos = 33.f;
			const float menu_button_width = 100.f;
			const float menu_button_height = 50.f;

			void CreateButtons();
			void CreateTexts();

			void InitializeButtons();
			void InitializeTexts();

			void UpdateSearchTypeText();
			void UpdateComparisonsText();
			void UpdateArrayAccessText();
			void UpdateNumberOfSticksText();
			void UpdateDelayText();
			void UpdateTimeComplexityText();
			
			void MenuButtonCallback();
			void RegisterButtonCallback();

			void Destroy();
		public:
			GameplayUIController();
			~GameplayUIController();

			void initialize() override;
			void update() override;
			void render() override;
			void show() override;
		};
	}
}

