#ifndef MERGE_H
#define MERGE_H

#include "sort.h"

class MergeSort : public Sort {       
  public:
	MergeSort(int *arr, size_t size) : Sort(arr, size) {}

	void execute() {
	  mergeSort(elements, 0, size - 1);
	}

	void mergeSort(int arr[], int l, int r) {
	  if (l < r) {
		int m = l+(r-l)/2;

		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	  }
	}

	void merge(int arr[], int l, int m, int r) { 
	  int i, j, k; 
	  int size1 = m - l + 1; 
	  int size2 =  r - m; 

	  int L[size1], R[size2];

	  for (i = 0; i < size1; i++)
		L[i] = arr[l + i];
	  for (j = 0; j < size2; j++)
		R[j] = arr[m + 1+ j];

	  i = 0;
	  j = 0;
	  k = l;
	  while (i < size1 && j < size2) { 
		if (L[i] <= R[j]) { 
		  arr[k] = L[i]; 
		  i++; 
		} else { 
		  arr[k] = R[j]; 
		  j++; 
		}
		k++; 
	  }

	  while (i < size1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	  }

	  while (j < size2) { 
		arr[k] = R[j];
		j++;
		k++;
	  }
	}

	inline std::string name() { return "MergeSort"; }
};

#endif
