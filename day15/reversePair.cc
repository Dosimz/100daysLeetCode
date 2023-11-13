#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    std::vector<int> temps;
    long long count = 0;   
    void mergeSort(vector<int>& nums, int lo, int hi){
        if(lo>=hi) return;
        int mid = lo + (hi-lo)/2;

        mergeSort(nums, lo, mid);
        mergeSort(nums, mid+1, hi);

        for(int u=lo; u<=hi; u++){
            temps[u] = nums[u];
        }

        
        int end = mid+1;
        for(int ui=lo; ui<=mid; ui++){
            while(end<=hi&&(long)temps[ui]>(long)temps[end]*2){
                end++;
            }
            count += end - mid -1;
        }
        // std::merge(nums.begin() + lo, nums.begin() + mid + 1, nums.begin() + mid + 1, nums.begin() + hi + 1, temps.begin() + lo);
        // std::copy(temps.begin() + lo, temps.begin() + hi + 1, nums.begin() + lo);

        int i = lo, j = mid+1;
        for(int p=lo; p<=hi; p++){
            if(i==mid+1){
                nums[p] = temps[j++];
            }else if(j==hi+1){
                nums[p] = temps[i++];
            }else if(temps[i]<temps[j]){
                nums[p] = temps[i++];
            }else{
                nums[p] = temps[j++];
            }
        }
    }


    int reversePairs(vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }
        int hi = nums.size()-1;
        temps.resize(hi+1);
        mergeSort(nums, 0, hi);
        return count;
    }

    // vector<int> temps;
    // int count=0;
 
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums = {1,3,2,3,1};
    // vector<int> expected = {3, 1, 2, 1, 0};
    int expected = 2;
    int actual = solution.reversePairs(nums);
    if (expected == actual) {
        cout << "Test case 1 passed." << endl;
    } else {
        cout << "Test case 1 failed." << endl;
    }

    // Test case 2
    nums = {2,4,3,5,1};
    expected = 3;
    actual = solution.reversePairs(nums);
    if (expected == actual) {
        cout << "Test case 2 passed." << endl;
    } else {
        cout << "Test case 2 failed." << endl;
    }

    // // Test case 3
    // nums = {2, 6, 5, 4, 3, 1};
    // expected = {3, 5, 4, 3, 2, 0};
    // actual = solution.countSmaller(nums);
    // if (expected == actual) {
    //     cout << "Test case 3 passed." << endl;
    // } else {
    //     cout << "Test case 3 failed." << endl;
    // }

    return 0;
}
