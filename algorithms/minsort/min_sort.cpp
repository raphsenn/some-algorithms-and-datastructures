#include "./min_sort.h"

void min_sort(int *arr, int length_of_arr) {
  for (int i = 0; i <  length_of_arr; i++) {
    int current_min = arr[i]; 
    int current_min_index = i; 

    for (int j = i; j < length_of_arr; j++) {
      if (arr[j] < current_min) {
        current_min = arr[j];
        current_min_index = j;
      }
    }
    // Perform Element swap in arr with current_min and i.
    int temp = arr[i];
    arr[i] = current_min;
    arr[current_min_index] = temp;
  }
}
