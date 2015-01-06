#pragma once

#include "Allocator.h"
#include "Game.h"

namespace Kuma
{
  //////////////////////////////////////////////////////////////////////////
  // Component
  //////////////////////////////////////////////////////////////////////////
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

  //////////////////////////////////////////////////////////////////////////
  // SystemComponent
  //////////////////////////////////////////////////////////////////////////
  template<typename T>
  class SystemComponent : public Component
  {
  public:
    virtual void Initialize() = 0;
    virtual void Update(float dt) = 0;
    virtual void Destroy() = 0;

    static void Register(const char *name, size_t blocksPerPage)
    {
      Game::Instance.systems.insert({ name, Game::Instance.allocator.DefineSystemComponent(name, sizeof(T), blocksPerPage) });
    }
  };
}
