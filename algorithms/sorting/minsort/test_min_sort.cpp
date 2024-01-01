#include <gtest/gtest.h>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <random>

#include "./min_sort.h"

TEST(min_sort, test_min_sort) {
  // Size of testing arrays.
  const int size = 100;

  int sorted_array[size];
  int testing_array[size];

  // Fill the arrays with numbers from 0 to 99.
  for (int i = 0; i < size; i++) {
    sorted_array[i] = i;
    testing_array[i] = i;
  }

  // Seed the random number generator with the current time
  std::srand(static_cast<unsigned int>(std::time(0)));

  // Perform testing:
  for (int i = 0; i < size; i++) {
    std::shuffle(testing_array, testing_array + size, std::default_random_engine(std::rand()));

    // Apply min_sort to the testing_array
    min_sort(testing_array, size);

    // Compare each element in sorted_array and testing_array
    for (int j = 0; j < size; j++) {
      EXPECT_EQ(sorted_array[j], testing_array[j]);
    }
  }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
