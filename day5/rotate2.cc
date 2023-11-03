#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*
逆时针旋转矩阵 90度
*/
public:    
    void rotate2(vector<vector<int>> &matrix){
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n-i; j++){
                int flag = matrix[i][j];
                matrix[i][j] = matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1] = flag;
            }
        }

        for(auto &line: matrix){
            reverse(line.begin(), line.end());
        }
    }

};