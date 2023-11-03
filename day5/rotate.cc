#include <iostream>
#include <vector>

using namespace std;

/*

[[1,2,3],
 [4,5,6],
 [7,8,9]]

[[1,4,3],
 [2,5,6],
 [7,8,9]]

顺时针旋转矩阵 90度

*/
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int flag = 0; 
        for(int i=0; i<matrix.size(); i++){
            for(int j=i; j<matrix.size(); j++){
                flag = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = flag;
            }
        }
        for(auto &line: matrix){
            reverse(line.begin(), line.end());
        }
    }
};