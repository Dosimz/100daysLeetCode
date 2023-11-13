#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void mergeSort(vector<int>& nums, int temps[], int lo, int hi){
        if(lo==hi) return;
        int mid = lo + (hi-lo)/2;

        mergeSort(nums,temps, lo, mid);
        mergeSort(nums, temps, mid+1, hi);

        for(int u=lo; u<=hi; u++){
            temps[u] = nums[u];
        }

        
        for(int ui=lo; ui<=mid; ui++){
            int end = mid+1;
            while(end<=hi&&(long)temps[ui]>(long)temps[end]*2){
                end++;
            }
            count += end - mid -1;
        }

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
        int hi = nums.size()-1;
        // temps.resize(hi+1);

        int temps[nums.size()];
        memset(temps,0,sizeof(temps));

        mergeSort(nums, temps, 0, hi);
        return count;
    }
public:
    // vector<int> temps;
    
    int count=0;
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
