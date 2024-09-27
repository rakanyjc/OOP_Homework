from grid import Grid
from sudoku import Sudoku

boxSize = 3
gridSize = 9
s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720"
sudoku = Sudoku(s, boxSize, gridSize)

for i in range(gridSize):
    for j in range(gridSize):
        inference = sudoku.getInference(i, j)
        print(f"({i},{j})'s inference is {inference}")