#pragma once

#include "Component.h"

namespace Kuma
{
  class RigidBody : public SystemComponent<RigidBody>
  {

    void Initialize();
    void Update(float dt);
    void Destroy();
  };
}
