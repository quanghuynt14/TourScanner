CXX=g++
CXXFLAGS=-ansi -pedantic -Wall -std=c++11
LDFLAGS=
EXEC=main
SRC=$(wildcard *.cpp)
OBJ=$(SRC:.cpp=.o)


all : $(EXEC)

main : $(OBJ)
	$(CXX) -o $@ $^ $(LDFLAGS)
%.o : %.cpp
	$(CXX) -c $< $(CXXFLAGS)
debug : $(OBJ)
	$(CXX) -g3 -o $@ $^ $(LDFLAGS)
clean : 
	rm -f *.o
mrproper : clean
	rm -f main debug


