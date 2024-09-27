import numpy as np

class Grid:
    def __init__(self, grid: np.array = None, boxSize: int = 0, gridSize: int = 0):
        self.boxSize = boxSize
        self.gridSize = gridSize
        self.grid = grid

    
    def getRow(self, row: int) -> np.array:
        return self.grid[row]
    
    
    def getColumn(self, column: int) -> np.array:
        return self.grid[:, column]
    
    
    def getBox(self, row: int, column: int) -> np.array:
        rowStart = row // self.boxSize
        columnStart = column // self.boxSize
        return self.grid[rowStart : rowStart + self.boxSize, columnStart : columnStart + self.boxSize]


    def getGrid(self) -> np.array:
        return self.grid
    