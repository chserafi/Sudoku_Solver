all: sudokusolver.cpp
  g++ -g -o sudokusolver sudokusolver.cpp

clean:
  $(RM) sudokusolver
