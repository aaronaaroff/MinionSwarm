#include "stdafx.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Game.h"
#include "PokeBall.h"
#include "Gru.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Name of new game button test
const wstring NewGameImage = L"images/new-game.png";


namespace Testing
{


	class CTestVisitor : public CItemVisitor
	{
	public:
		virtual void VisitMinion(CMinion *road) override { mNumMinions++; }

		int mNumMinions = 0;
	};

	TEST_CLASS(CNewGameTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}



		TEST_METHOD(TestGameOver)
		{
			CGame game;
			auto gru = make_shared<CGru>(&game);
			auto villain = make_shared<CPokeBall>(&game);

			villain->SetLocation(0, 0);
			gru->SetLocation(0, 0);

			Assert::IsTrue(game.GetGameOver());

		}
		
		TEST_METHOD(TestCNewGameMockHitTest)
		{
			// Create a newgamebutton to test
			CGame game;
			CNewGameMock newgamebutton(&game);

			// Give it a location
			// Always make the numbers different, in case they are mixed up
			newgamebutton.SetLocation(100, 200);

			// Center of the newgamebutton should be a true
			Assert::IsTrue(newgamebutton.HitTest(100, 200));

			// Left of the newgamebutton
			Assert::IsFalse(newgamebutton.HitTest(0, 0));

			// Right of the newgamebutton
			Assert::IsFalse(newgamebutton.HitTest(200, 200));

			// Above the newgamebutton
			Assert::IsFalse(newgamebutton.HitTest(100, 0));

			// Below the newgamebutton
			Assert::IsFalse(newgamebutton.HitTest(100, 300));

			// Of newgamebutton transparent pixel
			Assert::IsFalse(newgamebutton.HitTest(100 - 300 / 2 + 17, 200 - 117 / 2 + 16));
		}

	};
}