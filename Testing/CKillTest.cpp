#include "stdafx.h"
#include "CppUnitTest.h"
#include "Gru.h"
#include "Minion.h"
#include "Villain.h"
#include "DeleteItem.h"
#include "Game.h"
#include <stdio.h>
#include <time.h>
#include <dos.h>
#include <windows.h>

#include <iostream>
#include <stdlib.h>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

/// Arya Name for villain Construction
const wstring aryaName = L"Arya";

/// Blender Name for Villain Construction
const wstring blendName = L"Blender";

///Poke Ball Name for Villain Construction
const wstring pokeBallName = L"PokeBall";

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

			/*
			* here we test the villains killing gru
			* create villain, make gru, add gru to list
			* then we kill gru and see if the list is empty */
			

			auto arya = make_shared<CVillain>(&game, aryaName);
			arya->SetLocation(0, 0);
			auto gru1 = make_shared<CGru>(&game);
			gru1->SetLocation(0, 0);

			game.Add(arya);
			game.Add(gru1);
			game.Update(100);

			Assert::IsTrue(game.GetGameOver());

			
			auto ball = make_shared<CVillain>(&game, pokeBallName);
			ball->SetLocation(100, 100);
			auto gru2 = make_shared<CGru>(&game);
			gru2->SetLocation(100, 100);

			game.Add(ball);
			game.Add(gru2);
			game.Update(100);

			Assert::IsTrue(game.GetGameOver());

			auto blend = make_shared<CVillain>(&game, blendName);
			blend->SetLocation(300, 300);
			auto gru3 = make_shared<CGru>(&game);
			gru3->SetLocation(300, 300);

			game.Add(blend);
			game.Add(gru3);
			game.Update(100);

			Assert::IsTrue(game.GetGameOver());
			

		}


		TEST_METHOD(TestVillainKillMinion)
		{
			CGame game;

			/*
			* here we test the villains killing the minions
			* create villain, make minion, add minion to list
			* then we kill the minion and see if the list is empty */
			

			auto arya = make_shared<CVillain>(&game, aryaName);
			arya->SetLocation(0, 0);
			auto minion1 = make_shared<CMinion>(&game);
			minion1->SetLocation(0, 0);

			game.Add(minion1);
			game.Add(arya);
			game.KillMinions();

			CDeleteItem vis;
			game.Accept(&vis);

			Assert::IsTrue(vis.getMinions().size() == 0);

			
			auto ball = make_shared<CVillain>(&game, pokeBallName);
			ball->SetLocation(100, 100);
			auto minion2 = make_shared<CMinion>(&game);
			minion2->SetLocation(100, 100);

			game.Add(minion2);
			game.Add(ball);
			game.KillMinions();

			CDeleteItem vis2;
			game.Accept(&vis2);

			Assert::IsTrue(vis2.getMinions().size() == 0);

			auto blend = make_shared<CVillain>(&game, blendName);
			blend->SetLocation(300, 300);
			auto minion3 = make_shared<CMinion>(&game);
			minion3->SetLocation(300, 300);
			
			game.Add(minion3);
			game.Add(blend);
			game.KillMinions();

			CDeleteItem vis3;
			game.Accept(&vis3);

			Assert::IsTrue(vis3.getMinions().size() == 0);
			
		}


		TEST_METHOD(TestMinionKillGru)
		{
			CGame game;

			

			/*
			* here we test the villains killing gru
			* create villain, make gru, add gru to list
			* then we kill gru and see if the list is empty
			*/

			auto minion1 = make_shared<CMinion>(&game);
			minion1->SetLocation(0, 0);
			auto gru1 = make_shared<CGru>(&game);
			gru1->SetLocation(0, 0);

			game.Add(minion1);
			game.Add(gru1);
			game.Update(100);



			Assert::IsTrue(game.GetGameOver());


			auto minion2 = make_shared<CMinion>(&game);
			minion2->SetLocation(100, 100);
			auto gru2 = make_shared<CGru>(&game);
			gru2->SetLocation(100, 100);

			game.Add(minion2);
			game.Add(gru2);
			game.Update(100);

			Assert::IsTrue(game.GetGameOver());


			auto minion3 = make_shared<CMinion>(&game);
			minion3->SetLocation(300, 300);
			auto gru3 = make_shared<CGru>(&game);
			gru3->SetLocation(300, 300);

			game.Add(minion3);
			game.Add(gru3);
			game.Update(100);

			Assert::IsTrue(game.GetGameOver());


			


		}

		
		TEST_METHOD(TestVillainPoints)
		{
			CGame game;

			auto arya = make_shared<CVillain>(&game, aryaName);
			arya->SetLocation(0, 0);
			auto minion1 = make_shared<CMinion>(&game);
			minion1->SetLocation(0, 0);

			game.Add(arya);
			game.Add(minion1);
			game.Update(100);

			Assert::IsTrue(game.getTotalScore() == 1 || game.getTotalScore() == 15);

			CGame game2;

			auto ball = make_shared<CVillain>(&game, pokeBallName);
			ball->SetLocation(100, 100);
			auto minion2 = make_shared<CMinion>(&game);
			minion2->SetLocation(100, 100);

			game2.Add(ball);
			game2.Add(minion2);
			game2.Update(100);
			Assert::IsTrue(game2.getTotalScore() == 3 || game2.getTotalScore() == 15);
			
			CGame game3;

			auto blend = make_shared<CVillain>(&game, blendName);
			blend->SetLocation(300, 300);
			auto minion3 = make_shared<CMinion>(&game);
			minion3->SetLocation(300, 300);

			game3.Add(blend);
			game3.Add(minion3);
			game3.Update(100);
			Assert::IsTrue(game3.getTotalScore() == 2 || game3.getTotalScore() == 10);
		}
		
	};
}