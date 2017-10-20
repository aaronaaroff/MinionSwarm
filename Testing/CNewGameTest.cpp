#include "stdafx.h"
#include "CppUnitTest.h"
#include "Item.h"
#include "Game.h"
#include "Gru.h"

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



		TEST_METHOD(TestGameOver)
		{
			CGame game;
			auto gru = make_shared<CGru>(&game);
			//auto villain = make_shared<CVillain>(&game);

			//villain->SetLocation(0, 0);
			gru->SetLocation(0, 0);

			Assert::IsTrue(game.GetGameOver());

		}
		

	};
}