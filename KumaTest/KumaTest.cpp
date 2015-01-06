// KumaTest.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Game.h"

// Components
#include "RigidBody.h"


int _tmain(int argc, _TCHAR* argv[])
{
  using namespace Kuma;

  Game::BeginSetup();
  RigidBody::Register("RigidBody", 256);
  Game::EndSetup();

  Game::Begin();

	return 0;
}

