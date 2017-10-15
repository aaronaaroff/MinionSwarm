#include "stdafx.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Game.h"
#include "Minion.h"
#include "Gru.h"
#include "Villain.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;



namespace Testing
{	
	TEST_CLASS(NewGameTest)
	{
	public:
		
		TEST_METHOD(TestGameOver)
		{
			CGame game;
			auto gru = make_shared<CGru>(&game);
			auto villain = make_shared<CVillain>(&game);

			villain->SetLocation(0, 0);
			gru->SetLocation(0, 0);

			Assert::IsTrue(game.GetGameOver());

		}

	};
}