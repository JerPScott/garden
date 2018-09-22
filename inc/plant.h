#pragma once

#include "map.h"

namespace garden
{
  class plant : public map
  {
  public:
    plant(char fill);
  
    void grow();
  };
}
