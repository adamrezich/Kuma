#pragma once

#include "Allocator.h"

namespace Kuma
{
  class Component
  {
  public:

    enum class Type
    {
      None,
      System,
      User
    };

    virtual ~Component() = default;
    virtual void Initialize() = 0;

    Type type;
  };
}

