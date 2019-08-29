OBJECTS = main.cpp tester.cpp tester.h mocker.cpp mocker.h
STD = -std=c++17
MYFLAGS = -g -Wall
CXX = g++
EXEC = main

all: $(OBJECTS)
	$(CXX) $(STD) $(MYFLAGS) $(OBJECTS) -o $(EXEC)

clean: 
	rm $(EXEC)

