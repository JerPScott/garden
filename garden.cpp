#include <chrono>
#include <thread>

#include <cstdlib>

#include "plant.cpp"

int main()
{
  // seed random with current time.
  srand(time(0));

  while (true)
  {
    // Plant with + leaves
    garden::plant test_plant('+');

    // Set a seed in bottom middle.
    test_plant.set(
      garden::plant::ks_row_size/2,
      garden::plant::ks_col_size-1,
      test_plant.k_fill);

    // Set a seed in bottom left.
    test_plant.set(
      0,
      garden::plant::ks_col_size-1,
      test_plant.k_fill);

    // Set a seed in bottom right.
    test_plant.set(
      garden::plant::ks_row_size-1,
      garden::plant::ks_col_size-1,
      test_plant.k_fill);

    // Animate 75 frames growing each time.
    for (int i = 0; i< 75; i++)
    {
      test_plant.grow();
      test_plant.draw(std::cout);

      // Slow the animation to let the user see.
      std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
  }
}
