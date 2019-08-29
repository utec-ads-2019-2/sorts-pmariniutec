#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
  public:
	RadixSort(int *elements, size_t size) : Sort(elements, size) {}

	void execute() {
	  radixSort(elements, size);
	}

	void countSort(int *arr, int n, int exp) {
	  int output[n];
	  int i, count[10] = {0};

	  for (i = 0; i < n; i++)
		count[ (arr[i]/exp)%10 ]++;

	  for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	  for (i = n - 1; i >= 0; i--) {
		auto countIdx = (arr[i] / exp) % 10;
		auto idx = count[countIdx] - 1;
		output[idx] = arr[i];
		count[countIdx]--;
	  }

	  for (i = 0; i < n; i++)
		arr[i] = output[i];
	}

	void radixSort(int *arr, int n) {
	  int m = *std::max_element(arr, arr + n);

	  for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
	}

	inline std::string name() { return "RadixSort"; }
};

#endif
