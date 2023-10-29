#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {      
        // int len = nums.size();
        // if (len<1) return len;
        // int slow = 0;
        // for(int fast=0;fast<len;fast++){
        //     if(nums[fast]!=val) {
        //         nums[slow++] = nums[fast];
        //     }
        // }
        // return slow;
    // }
        int len = nums.size();
        if (len == 0) return 0;
        int i = 0, j = 0;
        while (j < len) {
            if (nums[j] == val) {
                j++;
            } else {
                nums[i++] = nums[j++];
            }
        }
        return i;
    }
};

Solution s  = Solution();
int main(){
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int len = s.removeElement(nums,val);
    cout << len << endl;
    for(int i=0;i<len;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}