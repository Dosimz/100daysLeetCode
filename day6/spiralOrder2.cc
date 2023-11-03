#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int up = 0, down = n-1;
        int left = 0, right = n-1;
        int num = 1;

        while(num<=n*n){
            for(int j=left; j<=right; j++){
                ans[up][j] = num++;
            }
            if(up<=down) up++;

            for(int j=up; j<=down; j++){
                ans[j][right] = num++;
            }
            if(right>=left) right--;

            for(int j=right; j>=left; j--){
                ans[down][j] = num++;
            }
            if (down>=up) down--;

            for(int j=down; j>=up; j--){
                ans[j][left] = num++;
            }
            if(left<=right) left++;
        }

        return ans;
    }
};