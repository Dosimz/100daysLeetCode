#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target, bool lower){
        int left =0, right=nums.size()-1;
        int targetIndex= 0;
        while(left<=right){
            int mid = left + (right-left)/2;

            if(nums[mid]<target){
                left = mid +1;
            }else if(nums[mid] > target){
                right = mid-1;
            }else if(nums[mid]==target&&lower){
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        if(lower)
            return left;
        else
            return left-1;
    }


    int countTarget(vector<int>& scores, int target) {
        int start = 0, end = 0;
        start = binarySearch(scores, target, true);
        end = binarySearch(scores, target, false);
        if(start<=end&&end<scores.size()&&scores[start]==target&&scores[end]==target){
        // start<=end    true
        // start>=0      falss
        // if(scores[start]==target&&scores[end]==target){
            return end-start+1;
        }
        return 0;
    }
};

int main(){
    Solution s;
    vector<int> testNums{2,2,3,4,4,4,5,6,6,8};
    auto res = s.countTarget(testNums, 4);
    cout<<res<<endl;
}