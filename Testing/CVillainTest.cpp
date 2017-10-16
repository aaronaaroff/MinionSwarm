#include "stdafx.h"
#include "CppUnitTest.h"
#include "Gru.h"
#include "Minion.h"
#include "Villain.h"
#include "PokeBall.h"
#include "Blender.h"
#include "AryaStark.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace Testing
{
	TEST_CLASS(CVillainTest)
	{
	public:
		/// TO Do -> test Villain kill functionality on minions
		/// To Do -> test Villain Type for Point Multiplier
		TEST_METHOD(TestVillainKillGru)
		{
			CGame game;
			auto arya = make_shared<CAryaStark>(&game);
			auto ball = make_shared<CPokeBall>(&game);
			auto blend = make_shared<CBlender>(&game);
			auto gru1 = make_shared<CGru>(&game);
			auto gru2= make_shared<CGru>(&game);
			auto gru3 = make_shared<CGru>(&game);

			arya->SetLocation(0, 0);
			gru1->SetLocation(0, 0);

			ball->SetLocation(100, 100);
			gru2->SetLocation(100, 100);

			blend->SetLocation(300, 300);
			gru3->SetLocation(300, 300);

			
		


		}

		TEST_METHOD(TestVillainKillMinion)
		{
			CGame game;
			auto arya = make_shared<CAryaStark>(&game);
			auto ball = make_shared<CPokeBall>(&game);
			auto blend = make_shared<CBlender>(&game);

			auto minion1 = make_shared<CMinion>(&game);
			auto minion2 = make_shared<CMinion>(&game);
			auto minion3 = make_shared<CMinion>(&game);

			arya->SetLocation(0, 0);
			minion1->SetLocation(0, 0);

			ball->SetLocation(100, 100);
			minion2->SetLocation(100, 100);

			blend->SetLocation(300, 300);
			minion3->SetLocation(300, 300);



		}

		TEST_METHOD(TestVillainPoints)
		{
			CGame game;
			auto arya = make_shared<CAryaStark>(&game);
			auto ball = make_shared<CPokeBall>(&game);
			auto blend = make_shared<CBlender>(&game);

			auto minion1 = make_shared<CMinion>(&game);
			auto minion2 = make_shared<CMinion>(&game);
			auto minion3 = make_shared<CMinion>(&game);

			arya->SetLocation(0, 0);
			minion1->SetLocation(0, 0);

			Assert::IsTrue(arya->GetPoints() == 1 || ball->GetPoints() == 5);

			ball->SetLocation(100, 100);
			minion2->SetLocation(100, 100);

			Assert::IsTrue(ball->GetPoints() == 3 || ball->GetPoints() == 15);

			blend->SetLocation(300, 300);
			minion3->SetLocation(300, 300);

			Assert::IsTrue(blend->GetPoints() == 2 || ball->GetPoints() == 10);
		}

	};
}