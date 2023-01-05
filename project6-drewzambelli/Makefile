CXX = g++
CXXFLAGS = -std=c++17 -g -Wall

SRC = '.'
EXEC = main

OBJ = Account.cpp General.cpp Post.cpp main.cpp

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(SRC)/$@ $(OBJ)


clean:
	rm -rf $(EXEC)

rebuild: clean all
