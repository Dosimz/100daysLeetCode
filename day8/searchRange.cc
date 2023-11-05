#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left =0, right =nums.size()-1;
        int start = 0;
        int end = 0;

        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] < target){
                left = mid+1;
            } else if(nums[mid] > target){
                right = mid - 1;
            } else if(nums[mid] == target){
                right = mid -1;
            }
        }
        start = left;
        left =0, right =nums.size()-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid] < target){
                left = mid+1;
            } else if(nums[mid] > target){
                right = mid - 1;
            } else if(nums[mid] == target){
                left = mid+1;
            }
        }
        end = right;
        
        // if (nums[start]==target)
        // 边界条件发生的情况。
        if (start <= end && start < nums.size() && nums[start] == target && nums[end] == target){
            return vector<int>{start, end};
        } else {
            return vector<int>{-1, -1};
        }
    }
};

int main(){
    Solution s;
    vector<int> testN{5,7,7,8,8,10};
    vector<int> result = s.searchRange(testN, 8);
    cout<<result[0]<<result[1]<<endl;
}

