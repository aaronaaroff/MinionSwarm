#include "stdafx.h"
#include "CppUnitTest.h"


#include "ChildView.h"

#include "Game.h"
#include "Gru.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{

	TEST_CLASS(PlayAreaTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}
		
		TEST_METHOD(TestGruInBounds)
		{
			CGame game;

			auto gru = make_shared<CGru>(&game);

			game.Add(gru);


			double imageHeight = gru->GetItemImageHeight();
			double imageWidth = gru->GetItemImageWidth();

			// Try to move gru past the edge of the game area on the x-axis
			gru->SetLocation(1000, 0);

			// Check that gru is still inside of the game area
			Assert::AreEqual(500 - imageWidth / 2, gru->GetX(), 0);


			// Try to move gru past the edge of the game area on the y-axis
			gru->SetLocation(0, 1000);

			// Check that gru is still inside of the game area
			Assert::AreEqual(500 - imageHeight / 2, gru->GetY(), 0);

			// Try to move gru out of the game area in a corner
			gru->SetLocation(1000, 1000);


			// Check that gru is still inside of the game area
			Assert::AreEqual(500 - imageWidth / 2, gru->GetX(), 0);
			Assert::AreEqual(500 - imageHeight / 2, gru->GetY(), 0);
		}

	};
}