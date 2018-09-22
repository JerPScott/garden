#pragma once

#include <array>
#include <iostream>

class map
{
public:
  static const int ks_row_size = 160; 
  static const int ks_col_size = 45;

  const char k_fill;
  const char k_blank;

  map(char fill, char blank);

  char get(int x, int y);

  void set(int x, int y, char val);

  void draw(std::ostream& os);
  bool draw(std::string const& file_name);

private:
  std::array<std::array<char, ks_row_size>, ks_col_size> tiles;
};
