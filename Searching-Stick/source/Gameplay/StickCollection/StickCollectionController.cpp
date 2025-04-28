#include "Gameplay/StickCollection/StickCollectionController.h"
#include "Gameplay/StickCollection/StickCollectionModel.h"
#include "Gameplay/StickCollection/StickCollectionView.h"
#include "Gameplay/StickCollection/Stick.h"
#include "Gameplay/GameplayService.h"
#include "Global/ServiceLocator.h"
#include "Sound/SoundService.h"
#include <random>

namespace Gameplay
{
	namespace StickCollection
	{
		using namespace UI::UIElement;
		using namespace Global;
		using namespace Graphics;
		void StickCollectionController::Destroy()
		{
			if (search_thread.joinable()) search_thread.join();

			delete stick_collection_view;
			delete stick_collection_model;
		}
		void StickCollectionController::InitializeSticks()
		{
			float rectangle_width = CalculateStickWidth();

			int i;
			for (i = 0; i < stick_collection_model->number_of_sticks; i++)
			{
				float rectangle_height = CalculateStickHeight(i);

				sf::Vector2f rectangle_size = sf::Vector2f(rectangle_width, rectangle_height);
				sticks[i]->stick_view->initialize(rectangle_size, sf::Vector2f(0, 0), 0, stick_collection_model->stick_color);
			}
		}
		float StickCollectionController::CalculateStickWidth()
		{
			float total_space = static_cast<float>(ServiceLocator::getInstance()->getGraphicService()->getGameWindow()->getSize().x);

			float total_spacing = stick_collection_model->space_percentage * total_space;

			float space_between = total_spacing / (stick_collection_model->number_of_sticks - 1);
			stick_collection_model->SetStickSpacing(space_between);

			float remaining_space = total_space - total_spacing;

			float rectangle_width = remaining_space / stick_collection_model->number_of_sticks;

			return rectangle_width;
			
		}
		void StickCollectionController::UpdateStickPosition()
		{
			int i;
			for (i = 0; i < sticks.size(); i++)
			{
				float x_pos = (i * sticks[i]->stick_view->getSize().x) + ((i + 1) * stick_collection_model->stick_spacing);
				float y_pos = stick_collection_model->stick_y_position - sticks[i]->stick_view->getSize().y;

				sticks[i]->stick_view->setPosition(sf::Vector2f(x_pos, y_pos));
			}
		}
		void StickCollectionController::ResetSticksColor()
		{
			int i;
			for (i = 0; i < sticks.size(); i++)
				sticks[i]->stick_view->setFillColor(stick_collection_model->stick_color);
		}
		void StickCollectionController::InitializeSticksArray()
		{
			int i;
			for (i = 0; i < stick_collection_model->number_of_sticks; i++)
				sticks.push_back(new Stick(i));
		}
		float StickCollectionController::CalculateStickHeight(int array_position)
		{
			return (static_cast<float>(array_position + 1) / stick_collection_model->number_of_sticks) * stick_collection_model->max_stick_height;
		}
		void StickCollectionController::ShuffleSticks()
		{
			std::random_device device;
			std::mt19937 random_engine(device());

			std::shuffle(sticks.begin(), sticks.end(), random_engine);
		}
		void StickCollectionController::ResetSearchStick()
		{
			stick_to_search = sticks[std::rand() % sticks.size()];
			stick_to_search->stick_view->setFillColor(stick_collection_model->search_stick_color);
		}
		void StickCollectionController::ResetVariables()
		{
			number_of_array_access = 0;
			number_of_comparisons = 0;
		}
		void StickCollectionController::ProcessLinearSearch()
		{
			int i;
			for (i = 0; i < sticks.size(); i++)
			{
				number_of_array_access++;
				number_of_comparisons++;

				ServiceLocator::getInstance()->getSoundService()->playSound(Sound::SoundType::Comparing_Sound);

				if (sticks[i] == stick_to_search)
				{
					stick_to_search->stick_view->setFillColor(stick_collection_model->found_stick_color);
					stick_to_search = nullptr;
					return;
				}
				else
				{
					sticks[i]->stick_view->setFillColor(stick_collection_model->processing_stick_color);
					std::this_thread::sleep_for(std::chrono::milliseconds(current_operation_delay));
					sticks[i]->stick_view->setFillColor(stick_collection_model->stick_color);
				}
			}
		}
		void StickCollectionController::ProcessSearchThreadState()
		{
			if (search_thread.joinable() && stick_to_search == nullptr)
				JoinThreads();
		}
		void StickCollectionController::JoinThreads()
		{
			search_thread.join();
		}
		StickCollectionController::StickCollectionController()
		{
			stick_collection_view = new StickCollectionView();
			stick_collection_model = new StickCollectionModel();
			InitializeSticksArray();
		}
		StickCollectionController::~StickCollectionController()
		{
			Destroy();
		}
		void StickCollectionController::Initialize()
		{
			InitializeSticks();
			Reset();
		}
		void StickCollectionController::Update()
		{
			ProcessSearchThreadState();
			int i;
			for (i = 0; i<sticks.size(); i++)
				sticks[i]->stick_view->update();
		}
		void StickCollectionController::Render()
		{
			int i;
			for (i = 0; i<sticks.size(); i++)
				sticks[i]->stick_view->render();
		}
		void StickCollectionController::Reset()
		{
			current_operation_delay = 0;

			ShuffleSticks();
			UpdateStickPosition();
			ResetSticksColor();
			ResetSearchStick();
			ResetVariables();
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
			this->search_type = type;
			switch (search_type)
			{
			case Gameplay::StickCollection::SearchType::LinearSearch:
				time_complexity = "O(n)";
				current_operation_delay = stick_collection_model->linear_search_delay;
				search_thread = std::thread(&StickCollectionController::ProcessLinearSearch, this);
				break;
			}
		}
		int StickCollectionController::GetNumberOfComparisons()
		{
			return number_of_comparisons;
		}
		int StickCollectionController::GetNumberOfArrayAccess()
		{
			return number_of_array_access;
		}
		int StickCollectionController::GetDelayMilliseconds()
		{
			return current_operation_delay;
		}
		sf::String StickCollectionController::GetTimeComplexity()
		{
			return time_complexity;
		}
	}
}
