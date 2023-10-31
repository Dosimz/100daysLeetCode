#include <iostream>
#include <vector>

using namespace std;


class NumMatrix {
public:
    vector<vector<int>> sumMatrix;

    NumMatrix(vector<vector<int>>& matrix) {
        sumMatrix.resize(matrix.size()+1, vector<int>(matrix[0].size()+1, 0));
        for(int i=1; i<sumMatrix.size();i++){
            for(int j=1; j<sumMatrix[0].size(); j++){
                sumMatrix[i][j] = sumMatrix[i-1][j] + sumMatrix[i][j-1] - sumMatrix[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = 0;
        res = sumMatrix[row2+1][col2+1] + sumMatrix[row1][col1] - sumMatrix[row2+1][col1] - sumMatrix[row1][col2+1];
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */