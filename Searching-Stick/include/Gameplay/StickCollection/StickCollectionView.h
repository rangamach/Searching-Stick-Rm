#pragma once

namespace Gameplay
{
	namespace StickCollection
	{
		class StickCollectionView
		{
		private:
			void Destroy();

		public:
			StickCollectionView();
			~StickCollectionView();

			void Initialize();
			void Update();
			void Render();

			void Reset();
		};
	}
}

