#pragma once

#include <unordered_map>
#include <string>

#include "Allocator.h"

namespace Kuma
{
  class Game
  {
  public:

    Game() {}

    static Game Instance;

    static void BeginSetup();
    static void EndSetup();
    static void Begin();

    Allocator allocator;

    std::unordered_map<std::string, Allocator::Unit *> systems;
  };
}


