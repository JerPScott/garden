#include <iostream>

#include "map.h"

map::map(char fill, char blank)
  : k_fill(fill)
  , k_blank(blank)
{
  for (auto& row : tiles)
  {
    for (auto& col : row)
    {
      col = k_blank;
    }
  }
}

char map::get(int x, int y)
{
#ifdef __DEBUG__
  if (x > ks_row_size-1 ||
      y > ks_col_size-1 ||
      x < 0 ||
      y < 0)
  {
    std::cerr << "ERROR : map::set : out of bounds" << std::endl;
    return 0;
  }
#endif // __DEBUG__
  return tiles[y][x];
}

void map::set(int x, int y, char val)
{
#ifdef __DEBUG__
  if (x > ks_row_size ||
      y > ks_col_size ||
      x < 0 ||
      y < 0)
  {
    std::cerr << "ERROR : map::set : out of bounds" << std::endl;
    return;
  }
#endif // __DEBUG__
  tiles[y][x] = val;
}

void map::draw(std::ostream& os)
{
  for (auto row : tiles)
  {
    for (auto col : row)
    {
      os << col;
    }
    os << std::endl;
  }
}

bool map::draw(std::string const& file_name)
{
  // TODO(Jeremy): Complete when done bitnam, png work.
  if (file_name.size() > 0)
    return false;
  else
    return false;
  return true;
}
