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
const wstring PokeballImage = L"images/pokeball.png";


namespace Testing
 {

	/** Mock class for testing CItem */
	class CItemMock : public CItem
	{
	public:
		/** Constructor
		* \param game The game this item is a member of */
		CItemMock(CGame *game) : CItem(game, PokeballImage) {}

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

	TEST_CLASS(CItemTest)
	{
	public:

		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestCItemConstruct)
		{
			CGame game;
			CItemMock item(&game);
		}
		TEST_METHOD(TestCItemGettersSetters)
		{
			// Construct an item to test
			CGame game;
			CItemMock item(&game);

			// Test initial values
			Assert::AreEqual(0, item.GetX(), 0);
			Assert::AreEqual(0, item.GetY(), 0);

			// Test SetLocation, GetX, and GetY
			item.SetLocation(10.5, 17.2);
			Assert::AreEqual(10.5, item.GetX(), 0.0001);
			Assert::AreEqual(17.2, item.GetY(), 0.0001);

			// Test a second with with different values
			item.SetLocation(-72, -107);
			Assert::AreEqual(-72, item.GetX(), 0.0001);
			Assert::AreEqual(-107, item.GetY(), 0.0001);

		}

		TEST_METHOD(TestCItemMockHitTest)
		{
			// Create a newgamebutton to test
			CGame game;
			CItemMock newgamebutton(&game);

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

		TEST_METHOD(TestCGameVisitor)
		{
			// Construct a game object
			CGame game;

			// Add some items of each time
			auto item1 = make_shared<CGru>(&game);
			auto item2 = make_shared<CMinion>(&game);
			//auto item3 = make_shared<CVillain>(&game);


			game.Add(item1);
			game.Add(item2);
			//game.Add(item3);


			CTestVisitor visitor;
			game.Accept(&visitor);
			Assert::AreEqual(1, visitor.mNumMinions,
				L"Visitor number of minions");
		}

	};
}