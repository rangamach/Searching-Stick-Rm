#pragma once

#include "UI/UIElement/RectangleShapeView.h"

namespace Gameplay
{
	namespace StickCollection
	{
		struct Stick
		{
		public:
			int data;
			UI::UIElement::RectangleShapeView* stick_view;

			Stick() {}
			Stick(int data)
			{
				this->data = data;
				stick_view = new UI::UIElement::RectangleShapeView();
			}
			~Stick() { delete stick_view; }
		};
	}
}

