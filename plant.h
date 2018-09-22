#pragma once

#include "map.cpp"

namespace garden
{
  class plant : public map
  {
  public:
    plant(char fill);
  
    void grow();
  };
}
