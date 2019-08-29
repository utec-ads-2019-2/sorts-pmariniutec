#include <iostream>
#include <cassert>
#include <string>

#include "mocker.h"
#include "tester.h"
#include "bubble.h"
#include "select.h"
#include "insert.h"
#include "shell.h"
#include "quick.h"
#include "merge.h"

#define NUMBER_OF_TESTS 1000

Mocker mocker;

void executeTests();
void printArray(int *, size_t);

int main(int argc, char* argv[]) {
  std::cout << "===========================================================" << '\n';
  std::cout << "\tSorts Practice" << '\n';
  std::cout << "===========================================================" << '\n' << '\n';

  executeTests();

  return EXIT_SUCCESS;
}

void executeTests() {
  for (int i = 0; i < NUMBER_OF_TESTS; ++i) {
	size_t size = mocker.generateRandomInt();
	int *array = mocker.generateRandomIntArray(size);
	Tester::sorts(array, size);
	std::cout << "Passed test: " << i + 1 << '\n';
  }
}

void printArray(int *array, size_t size) {
  for (int i = 0; i < size; i++) {
	std::cout << array[i] << " ";
  }
  std::cout << '\n';
}
