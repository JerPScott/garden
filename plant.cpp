#include "map.h"
#include "plant.h"

namespace garden
{
  plant::plant(char fill)
    : map(fill, ' ')
  { }
  
  void plant::grow()
  {
    for (int x = 0; x < ks_row_size; x++)
    {
      for (int y = 0; y < ks_col_size; y++)
      {
        // skip filled spaces
        if (get(x, y) == k_fill)
        {
          continue;
        }
        
        int seed = 10;
        int border_count = 0;
  
        // check for plant in -x
        if (x-1 >= 0 &&
            get(x-1, y) == k_fill)
        {
          seed = 5;
          border_count++;
        }
        // check for plant in +x
        if (x+1 < ks_row_size &&
            get(x+1, y) == k_fill)
        {
          seed = 5;
          border_count++;
        }
        // check for plant in -y
        if (y-1 >= 0 &&
            get(x, y-1) == k_fill)
        {
          border_count++;
        }
        // check for plant in +y
        if (y+1 < ks_col_size &&
            get(x, y+1) == k_fill)
        {
          seed = 2;
          border_count++;
        }
  
        if (border_count == 1 && (rand()%seed == 1))
        {
          set(x, y, k_fill);
        }
      }
    }
  }
}

