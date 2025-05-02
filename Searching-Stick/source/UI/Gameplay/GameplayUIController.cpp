#include "../../include/UI/Gameplay/GameplayUIController.h"
#include "Global/Config.h"
#include "Global/ServiceLocator.h"
#include <Gameplay/StickCollection/StickCollectionModel.h>
#include <Main/GameService.h>

namespace UI
{
	namespace GameplayUI
	{
		using namespace Global;
		using namespace Main;

		void GameplayUIController::Destroy()
		{
			delete menu_button;

			delete search_type_text;
			delete number_of_comparisons_text;
			delete number_of_array_access_text;
			delete number_of_sticks_text;
			delete delay_text;
			delete time_complexity_text;
		}

		GameplayUIController::GameplayUIController()
		{
			CreateTexts();
			CreateButtons();
		}

		GameplayUIController::~GameplayUIController()
		{
			Destroy();
		}

		void GameplayUIController::initialize()
		{
			InitializeTexts();
			InitializeButtons();
			RegisterButtonCallback();
		}
		void GameplayUIController::update()
		{
			UpdateArrayAccessText();
			UpdateComparisonsText();
			UpdateDelayText();
			UpdateNumberOfSticksText();
			UpdateSearchTypeText();
			UpdateTimeComplexityText();

			menu_button->update();
		}
		void GameplayUIController::render()
		{
			search_type_text->render();
			number_of_comparisons_text->render();
			number_of_array_access_text->render();
			number_of_sticks_text->render();
			delay_text->render();
			time_complexity_text->render();

			menu_button->render();
		}
		void GameplayUIController::show()
		{
			search_type_text->show();
			number_of_comparisons_text->show();
			number_of_array_access_text->show();
			number_of_sticks_text->show();
			delay_text->show();
			time_complexity_text->show();

			menu_button->show();
		}
		void GameplayUIController::CreateButtons()
		{
			menu_button = new UIElement::ButtonView();
		}
		void GameplayUIController::CreateTexts()
		{
			search_type_text = new UIElement::TextView();
			number_of_comparisons_text = new UIElement::TextView();
			number_of_array_access_text = new UIElement::TextView();
			number_of_sticks_text = new UIElement::TextView();
			delay_text = new UIElement::TextView();
			time_complexity_text = new UIElement::TextView();
		}
		void GameplayUIController::InitializeButtons()
		{
			menu_button->initialize("Menu", Config::menu_button_large_texture_path, menu_button_width, menu_button_height, sf::Vector2f(menu_button_x_pos, menu_button_y_pos));
		}
		void GameplayUIController::InitializeTexts()
		{
			search_type_text->initialize("Search Type: Linear Search", sf::Vector2f(search_type_text_x_pos, text_y_pos), UIElement::FontType::BUBBLE_BOBBLE, font_size);
			number_of_comparisons_text->initialize("Number of Comparisons: ", sf::Vector2f(comparisons_text_x_pos, text_y_pos), UIElement::FontType::BUBBLE_BOBBLE, font_size);
			number_of_array_access_text->initialize("Number of Array Access: ", sf::Vector2f(array_access_text_x_pos, text_y_pos), UIElement::FontType::BUBBLE_BOBBLE, font_size);
			number_of_sticks_text->initialize("Number of Sticks: ", sf::Vector2f(number_of_sticks_text_x_pos, text_y_pos2), UIElement::FontType::BUBBLE_BOBBLE, font_size);
			delay_text->initialize("Delay: ", sf::Vector2f(delay_text_x_pos, text_y_pos2), UIElement::FontType::BUBBLE_BOBBLE, font_size);
			time_complexity_text->initialize("Time Complexity: ", sf::Vector2f(time_complexity_text_x_pos, text_y_pos2), UIElement::FontType::BUBBLE_BOBBLE, font_size);
		}
		void GameplayUIController::UpdateSearchTypeText()
		{
			Gameplay::StickCollection::SearchType new_search_type = ServiceLocator::getInstance()->GetGameplayService()->GetCurrentSearchType();

			switch (new_search_type)
			{
			case Gameplay::StickCollection::SearchType::LinearSearch:
				search_type_text->setText("Linear Search");
				break;
			case Gameplay::StickCollection::SearchType::BinarySearch:
				search_type_text->setText("Binary Search");
				break;
			}
			search_type_text->update();
		}
		void GameplayUIController::UpdateComparisonsText()
		{
			int number_of_comparisons = ServiceLocator::getInstance()->GetGameplayService()->GetNumberOfComparisons();
			sf::String number_of_comparisons_string = "Number of Comparisons: " + std::to_string(number_of_comparisons);

			number_of_comparisons_text->setText(number_of_comparisons_string);
			number_of_comparisons_text->update();
		}
		void GameplayUIController::UpdateArrayAccessText()
		{
			int number_of_array_access = ServiceLocator::getInstance()->GetGameplayService()->GetNumberOfArrayAccess();
			sf::String number_of_array_access_string = "Number of Array Access: " + std::to_string(number_of_array_access);
			
			number_of_array_access_text->setText(number_of_array_access_string);
			number_of_array_access_text->update();
		}
		void GameplayUIController::UpdateNumberOfSticksText()
		{
			int number_of_sticks = ServiceLocator::getInstance()->GetGameplayService()->GetNumberOfSticks();
			sf::String number_of_sticks_string = "Number of Sticks: " + std::to_string(number_of_sticks);

			number_of_sticks_text->setText(number_of_sticks_string);
			number_of_sticks_text->update();
		}
		void GameplayUIController::UpdateDelayText()
		{
			int delay = ServiceLocator::getInstance()->GetGameplayService()->GetDelayMilliseconds();
			sf::String delay_string = "Delay (ms): " + std::to_string(delay);

			delay_text->setText(delay_string);
			delay_text->update();
		}
		void GameplayUIController::UpdateTimeComplexityText()
		{
			sf::String time_complexity = ServiceLocator::getInstance()->GetGameplayService()->GetTimeComplexity();
			sf::String time_complexity_string = "Time Complexity " + time_complexity;

			time_complexity_text->setText(time_complexity_string);
			time_complexity_text->update();
		}
		void GameplayUIController::MenuButtonCallback()
		{
			ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::BUTTON_CLICK);
			ServiceLocator::getInstance()->GetGameplayService()->Reset();
			GameService::setGameState(GameState::MAIN_MENU);
		}
		void GameplayUIController::RegisterButtonCallback()
		{
			menu_button->registerCallbackFuntion(std::bind(&GameplayUIController::MenuButtonCallback, this));
		}
	}
}
