#include "stdafx.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Game.h"
#include "Minion.h"
#include "Gru.h"
#include "Villain.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Name of new game button test
const wstring NewGameImage = L"images/new-game.png";


namespace Testing
{

	/** Mock class for testing CItem */
	class CNewGameMock : public CItem
	{
	public:
		/** Constructor
		* \param game The game this item is a member of */
		CNewGameMock(CGame *game) : CItem(game, NewGameImage) {}

		/** Draw the item
		* \param graphics The graphics context to draw on */
		virtual void Draw(Gdiplus::Graphics *graphics) {}

		/** Accept a visitor
		* \param visitor The visitor we accept */
		virtual void Accept(CItemVisitor *visitor) override { }

	};

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

		TEST_METHOD(TestCNewGameConstruct)
		{
			CGame game;
			CNewGameMock item(&game);
		}
		TEST_METHOD(TestCNewGameGettersSetters)
		{
			// Construct an item to test
			CGame game;
			CNewGameMock item(&game);

			// Test initial values
			Assert::IsFalse(game.GetResetGameStatus());

			game.SetResetGameStatus(true);

			Assert::IsTrue(game.GetResetGameStatus());


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