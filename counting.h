#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>
#include <vector>

class CountingSort : public Sort {       
  public:
	CountingSort(int *elements, size_t size) : Sort(elements, size) {}

	void execute() {
	  int max = *std::max_element(elements, elements + size); 
	  int min = *std::min_element(elements, elements + size); 
	  int range = max - min + 1; 

	  std::vector<int> count(range), output(size); 

	  for(int i = 0; i < size; i++) 
		count[elements[i]-min]++; 

	  for(int i = 1; i < count.size(); i++) 
		count[i] += count[i-1]; 

	  for(int i = size - 1; i >= 0; i--) {  
		output[count[elements[i] - min] -1 ] = elements[i];  
		count[elements[i]-min]--;  
	  } 

	  for(int i = 0; i < size; i++) 
		elements[i] = output[i]; 
	}  

	inline std::string name() { return "CountingSort"; }

  private:
	const int RANGE = 255;
};

#endif
