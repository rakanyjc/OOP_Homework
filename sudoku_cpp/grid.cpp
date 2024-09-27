#include "grid.h"

Grid::Grid(){
    grid = nullptr;
    BoxSize = GridSize = 0;
}

Grid::Grid(int **Grid, int BoxSize, int GridSize){
    this->BoxSize = BoxSize;
    this->GridSize = GridSize;
    grid = new int*[GridSize];
    for(int i = 0; i < GridSize; i++){
        grid[i] = new int [GridSize];
    }
    for(int i = 0; i < GridSize; i++){
        for(int j = 0; j < GridSize; j++){
            grid[i][j] = Grid[i][j];
        }
    }
}

Grid::Grid(const Grid& g){
    BoxSize = g.BoxSize;
    GridSize = g.GridSize;
    grid = new int*[GridSize];
    for(int i = 0; i < GridSize; i++){
        grid[i] = new int [GridSize];
    }
    for(int i = 0; i < GridSize; i++){
        for(int j = 0; j < GridSize; j++){
            grid[i][j] = g.grid[i][j];
        }
    }
}

Grid& Grid::operator=(const Grid& g){
    if(this != &g){
        this->BoxSize = g.BoxSize;
        this->GridSize = g.GridSize;
        this->grid = new int*[this->GridSize];
        for(int i = 0; i < this->GridSize; i++){
            this->grid[i] = new int [this->GridSize];
        }
        for(int i = 0; i < this->GridSize; i++){
            for(int j = 0; j < this->GridSize; j++){
                this->grid[i][j] = g.grid[i][j];
            }
        }
    }
    return *this;
}

Grid::~Grid(){
    clear();
}

void Grid::clear(){
    for(int i = 0; i < GridSize; i++){
        delete grid[i];
    }
    delete grid;
    BoxSize = 0;
    GridSize = 0;
}

int* Grid::getRow(int row){
    int* ROW = new int[GridSize];
    for(int i = 0; i < GridSize; i++){
        ROW[i] = grid[row][i];
    }
    return ROW;
}

int* Grid::getColumn(int column){
    int *COLUMN = new int[GridSize];
    for(int i = 0; i < GridSize; i++){
        COLUMN[i] = grid[i][column];
    }
    return COLUMN;
}

int** Grid::getBox(int row, int column){
    int **BOX = new int*[BoxSize];
    for(int i = 0; i < BoxSize; i++){
        BOX[i] = new int[BoxSize];
    }
    int rowStart = row / BoxSize;
    int columnStart = column / BoxSize;
    for(int i = 0; i < BoxSize; i++){
        for(int j = 0; j < BoxSize; j++){
            BOX[i][j] = grid[3 * rowStart + i][3 * columnStart + j];
        }
    }
    return BOX;
}

int Grid::getBoxSize(){
    return BoxSize;
}

int Grid::getGridSize(){
    return GridSize;
}

int** Grid::getGrid(){
    return grid;
}
