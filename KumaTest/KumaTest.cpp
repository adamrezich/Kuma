// KumaTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"


int _tmain(int argc, _TCHAR* argv[])
{
  using namespace Kuma;
  Game::BeginSetup();
  Game::EndSetup();
  Game::Begin();
	return 0;
}

