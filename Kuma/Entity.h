#pragma once

#include <unordered_map>
#include <string>

#include "Constants.h"
#include "Component.h"

namespace Kuma
{
  class Entity
  {
    std::unordered_map<std::string, Component *> systemComponents;

  public:
    Entity()
    {
    }

    //AddSystemComponent
  };
}
