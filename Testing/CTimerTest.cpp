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

			// Make 10 seconds elapse in the game
			game.Update(10);

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 10);


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
//			timer->PauseTimer();

			game.Update(5000);

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 10);




		}


		TEST_METHOD(TestCTimerReset)
		{
			// Construct a game object
			CGame game;

			auto timer = make_shared<CTimer>(&game);

			game.Add(timer);

			// Make 10 seconds elapse in the game
			game.Update(10000);

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 10);

			//Call function to reset the game
			game.ResetGame();

			// Check that the timer has incremented 10 seconds
			Assert::IsTrue(timer->GetElpasedTime() == 0);




		}
	};
}