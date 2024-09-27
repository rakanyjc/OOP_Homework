import numpy as np
from grid import Grid

class Sudoku(Grid):
    def __init__(self, s: str, boxSize: int, gridSize: int):
        grid = self.parse(s, gridSize)
        super().__init__(grid, boxSize, gridSize)
    
    
    def parse(self, s: str, gridSize: int) -> np.array:
        array = np.array([int(char) for char in s])
        array_2d = array.reshape(gridSize, gridSize)
        return array_2d
    
    def getInference(self, row: int, column: int) -> np.array:
        if self.grid[row, column] == 0:
            Row = self.getRow(row)
            Column = self.getColumn(row)
            Box = self.getBox(row, column)

            flag = np.zeros(9, dtype=int)
            l = []

            for num in Row:
                if num != 0:
                    flag[num - 1] = 1
            for num in Column:
                if num != 0:
                    flag[num - 1] = 1
            for num in Box.flat:
                if num != 0:
                    flag[num - 1] = 1


            for i in range(len(flag)):
                if flag[i] == 0:
                    l.append(i + 1)
            
            inference = np.array(l)
        
        else:
            l = []
            l.append(self.grid[row, column])
            inference = np.array(l)
        return inference