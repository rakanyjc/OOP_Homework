#include <iostream>
#include <string>
#include "grid.cpp"
#include "sudoku.cpp"
using namespace std;

void printVector(vector<int> v, int row, int column){
    cout << "(" << row << "," << column << ")'s inference is ";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main(){
    int boxSize = 3;
    int gridSize = 9;
    string s = "017903600000080000900000507072010430000402070064370250701000065000030000005601720";
    Sudoku sudoku(s, boxSize, gridSize);

    for(int i = 0; i < gridSize; i++){
        for(int j = 0; j < gridSize; j++){
            vector<int> v = sudoku.getInference(i, j);
            printVector(v, i, j);
        }
    }
    return 0;
}
