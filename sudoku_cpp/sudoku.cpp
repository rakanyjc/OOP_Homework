#include "sudoku.h"

Sudoku::Sudoku():Grid(){}

Sudoku::Sudoku(int **grid, int boxSize, int gridSize):Grid(grid, boxSize, gridSize){}

Sudoku::Sudoku(string s, int boxSize, int gridSize):Grid(parse(s, gridSize), boxSize, gridSize){}

Sudoku::~Sudoku(){}

int** Sudoku::parse(string s, int gridSize){
    int **g = new int*[gridSize];
    for(int i = 0; i < gridSize; i++){
        g[i] = new int[gridSize];
    }

    for(int i = 0; i < s.length(); i++){
        int number = s[i] - '0';
        int row = i / gridSize;
        int column = i % gridSize;
        g[row][column] = number;
    }
    
    return g;
}

vector<int> Sudoku::getInference(int row, int column){
    int **grid = getGrid();
    vector<int> v;
    if(grid[row][column] != 0){
        v.push_back(grid[row][column]);
    }
    else{
        int *ROW = getRow(row);
        int *COLUMN = getColumn(column);
        int **BOX = getBox(row, column);
        int gridSize = getGridSize();
        int boxSize = getBoxSize();
        vector<bool> flag(gridSize);
        for(int i = 0; i < gridSize; i++){
            flag[i] = false;
        }
        for(int i = 0; i < gridSize; i++){
            if(ROW[i] != 0){
                flag[ROW[i]] = true;
            }
            if(COLUMN[i] != 0){
                flag[COLUMN[i]] = true;
            }
        }
        for(int i = 0; i < boxSize; i++){
            for(int j = 0; j < boxSize; j++){
                if(BOX[i][j] != 0){
                    flag[BOX[i][j]] = true;
                }
            }
        }

        for(int i = 1; i <= gridSize; i++){
            if(!flag[i]){
                v.push_back(i);
            }
        }
    }
    return v;
}

