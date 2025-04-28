#pragma once

#include <SFML/Graphics.hpp>

namespace Gameplay
{
	namespace StickCollection
	{
		enum class SearchType
		{
			LinearSearch,
			BinarySearch,
		};
		class StickCollectionModel
		{
		public:
			const float max_stick_height = 820.f;
			float stick_spacing = 25.f;
			const float stick_y_position = 1020.f;
			float space_percentage = 0.50f;

			const sf::Color stick_color = sf::Color::White;
			const sf::Color search_stick_color = sf::Color::Blue;
			const sf::Color found_stick_color = sf::Color::Green;
			const sf::Color processing_stick_color = sf::Color::Red;

			int linear_search_delay = 120;
			int binary_search_delay = 240;
			int number_of_sticks = 100;

			StickCollectionModel();
			~StickCollectionModel();

			void Initialize();
			void Update();

			void SetStickSpacing(float space);
		};
	}
}

