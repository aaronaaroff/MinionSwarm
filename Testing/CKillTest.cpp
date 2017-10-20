#include "stdafx.h"
#include "CppUnitTest.h"
#include "Gru.h"
#include "Minion.h"
#include "Villain.h"
#include "Game.h"

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

			std::vector<std::shared_ptr<CItem> > grukill;

			/*
			* here we test the villains killing gru
			* create villain, make gru, add gru to list
			* then we kill gru and see if the list is empty
			

			auto arya = make_shared<CVillain>(&game);
			arya->SetLocation(0, 0);
			auto gru1 = make_shared<CGru>(&game);
			grukill.push_back(gru1);
			gru1->SetLocation(0, 0);

			Assert::IsTrue(grukill.size() == 0);


			auto ball = make_shared<CVillain>(&game);
			ball->SetLocation(100, 100);
			auto gru2 = make_shared<CGru>(&game);
			grukill.push_back(gru2);
			gru2->SetLocation(100, 100);

			Assert::IsTrue(grukill.size() == 0);

			auto blend = make_shared<CVillain>(&game);
			blend->SetLocation(300, 300);
			auto gru3 = make_shared<CGru>(&game);
			grukill.push_back(gru3);
			gru3->SetLocation(300, 300);

			Assert::IsTrue(grukill.size() == 0);
		
		*/

		}

		TEST_METHOD(TestVillainKillMinion)
		{
			CGame game;
			std::vector<std::shared_ptr<CItem> > minionkill;

			/*
			* here we test the villains killing the minions
			* create villain, make minion, add minion to list
			* then we kill the minion and see if the list is empty
			
			auto arya = make_shared<CVillain>(&game);
			arya->SetLocation(0, 0);
			auto minion1 = make_shared<CMinion>(&game);
			minionkill.push_back(minion1);
			minion1->SetLocation(0, 0);

			Assert::IsTrue(minionkill.size() == 0);

			auto ball = make_shared<CVillain>(&game);
			ball->SetLocation(100, 100);
			auto minion2 = make_shared<CMinion>(&game);
			minionkill.push_back(minion2);
			minion2->SetLocation(100, 100);

			Assert::IsTrue(minionkill.size() == 0);

			auto blend = make_shared<CVillain>(&game);
			blend->SetLocation(300, 300);
			auto minion3 = make_shared<CMinion>(&game);
			minionkill.push_back(minion3);
			minion3->SetLocation(300, 300);

			Assert::IsTrue(minionkill.size() == 0);
			*/
		}


		TEST_METHOD(TestMinionKillGru)
		{
			CGame game;

			std::vector<std::shared_ptr<CItem> > grukill;

			/*
			* here we test the villains killing gru
			* create villain, make gru, add gru to list
			* then we kill gru and see if the list is empty
			*/

			auto minion1 = make_shared<CMinion>(&game);
			minion1->SetLocation(0, 0);
			auto gru1 = make_shared<CGru>(&game);
			grukill.push_back(gru1);
			gru1->SetLocation(0, 0);

			Assert::IsTrue(grukill.size() == 0);


			auto minion2 = make_shared<CMinion>(&game);
			minion2->SetLocation(100, 100);
			auto gru2 = make_shared<CGru>(&game);
			grukill.push_back(gru2);
			gru2->SetLocation(100, 100);

			Assert::IsTrue(grukill.size() == 0);

			auto minion3 = make_shared<CMinion>(&game);
			minion3->SetLocation(300, 300);
			auto gru3 = make_shared<CGru>(&game);
			grukill.push_back(gru3);
			gru3->SetLocation(300, 300);

			Assert::IsTrue(grukill.size() == 0);


		}

		/*
		TEST_METHOD(TestVillainPoints)
		{
			CGame game;

			auto arya = make_shared<CVillain>(&game);
			arya->SetLocation(0, 0);
			auto minion1 = make_shared<CMinion>(&game);
			minion1->SetLocation(0, 0);

			Assert::IsTrue(arya->GetPoints() == 1 || arya->GetPoints() == 5);

			auto ball = make_shared<CVillain>(&game);
			ball->SetLocation(100, 100);
			auto minion2 = make_shared<CMinion>(&game);
			minion2->SetLocation(100, 100);

			Assert::IsTrue(ball->GetPoints() == 3 || ball->GetPoints() == 15);
			
			auto blend = make_shared<CVillain>(&game);
			blend->SetLocation(300, 300);
			auto minion3 = make_shared<CMinion>(&game);
			minion3->SetLocation(300, 300);

			Assert::IsTrue(blend->GetPoints() == 2 || blend->GetPoints() == 10);
		}
		*/
	};
}