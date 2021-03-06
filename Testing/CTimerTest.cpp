#include "stdafx.h"
#include "CppUnitTest.h"
#include "Game.h"
#include "Timer.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CTimerTest)
	{
	public:
		TEST_METHOD_INITIALIZE(methodName)
		{
			extern wchar_t g_dir[];
			::SetCurrentDirectory(g_dir);
		}

		TEST_METHOD(TestCTimerConstruction)
		{
			// Construct a game object
			CGame game;

			auto timer = make_shared<CTimer>(&game);
		}

		TEST_METHOD(TestCTimerTimeElapsed)
		{
			// Construct a game object
			CGame game;

			auto timer = make_shared<CTimer>(&game);

			game.Add(timer);

			// Make 3 seconds elapse in the game
			game.Update(3);

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 3);


		}

		TEST_METHOD(TestCTimerPaused)
		{
			// Construct a game object
			CGame game;

			auto timer = make_shared<CTimer>(&game);

			game.Add(timer);

			// Make 10 seconds elapse in the game
			game.Update(10);

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 10);

			//Call function to paused the game
			timer->setActive(false);

			game.Update(5000);

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 10);




		}


	
	};
}