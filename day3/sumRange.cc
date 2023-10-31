#include <iostream>
#include <vector>

using namespace std;

// class NumArray {
// public:
//     vector<int> nums;

//     NumArray(vector<int>& nums) {
//         this->nums = nums;
//     }
    
//     int sumRange(int left, int right) {
//         int res = 0;
//         while(left<=right){
//             res += this->nums[left++];
//         }
//         return res;
//     }
// };
class NumArray {
public:
    vector<int> sumNums;


    NumArray(vector<int>& nums) {
        sumNums.resize(nums.size()+1);
        for (int i=1; i<sumNums.size(); i++){
            this->sumNums[i] = this->sumNums[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int left, int right) {
        int res = 0;
        res = sumNums[right+1] - sumNums[left];
        return res;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
