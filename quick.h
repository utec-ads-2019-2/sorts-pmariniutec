#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
  public:
	QuickSort(int *elements, size_t size) : Sort(elements, size) {}

	void execute() {
	  quickSort(elements, 0, size - 1);
	}

	int partition(int arr[], int low, int high) {
	  int pivot = arr[high];
	  int i = low - 1;

	  for (int j = low; j <= high - 1; ++j) {
		if (arr[j] < pivot) {
		  i++;
		  std::swap(arr[i], arr[j]);
		}
	  }
	  std::swap(arr[i + 1], arr[high]);
	  return i + 1;
	}

	void quickSort(int arr[], int low, int high) {
	  if (low < high) {
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	  }
	}

	inline std::string name() { return "QuickSort"; }
};

#endif
