#ifndef GRID_H
#define GRID_H

class Grid
{
    int **grid, BoxSize, GridSize;
public:
    Grid();
    Grid(int **grid, int BoxSize, int GridSize);
    Grid(const Grid& g);
    Grid& operator=(const Grid& g);
    ~Grid();
    void clear();
    int* getRow(int row);
    int* getColumn(int column);
    int** getBox(int row, int column);
    int getBoxSize();
    int getGridSize();
    int** getGrid();
};


#endif