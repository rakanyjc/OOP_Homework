#ifndef SUDOKU_H
#define SUDOKU_H
#include "grid.h"
#include <vector>
#include <string>
using namespace std;

class Sudoku: public Grid{
public:
    Sudoku();
    Sudoku(int **grid, int boxSize, int gridSize);
    Sudoku(string s, int boxSize, int gridSize);
    ~Sudoku();
    int** parse(string s, int gridSize);
    vector<int> getInference(int row, int column);
};

#endif