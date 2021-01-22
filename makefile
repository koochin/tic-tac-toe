CXX=g++
CXXFLAGS= -g -std=c++17 -Wall -Werror
SRC = $(shell find src/*.cpp)
OBJ_t = $(SRC:.cpp=.o)
OBJ = $(subst src/, build/, $(OBJ_t));
exe = main

$(shell mkdir -p build)

.PHONY: clean

$(exe): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(exe) $(OBJ)

build/main.o: src/main.cpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o build/main.o

build/%.o: src/%.cpp header/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf build/*.o $(exe) rm -d build