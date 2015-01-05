#pragma once

#include "Allocator.h"

namespace Kuma
{
  class Game
  {
    Allocator allocator;
    static Game Instance;

  public:
    static void BeginSetup();
    static void EndSetup();
    static void Begin();
  };
}


