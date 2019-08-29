#ifndef SORT_H
#define SORT_H

#include <algorithm>
#include <string>

class Sort {
  protected:
	int *elements;
	size_t size;

  public:
	Sort(int *elements, size_t size) : elements(elements), size(size) {}

	virtual void execute() = 0;

	virtual std::string name() = 0;
};

#endif
