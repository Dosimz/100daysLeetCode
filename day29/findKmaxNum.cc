#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};




class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int lo = 0,  hi = nums.size()-1;
        int n = nums.size();
        while(lo<=hi){
            int p = partition(nums, lo, hi);
            if(p==(n-k)){
                return nums[p];
            }
            if(p>(n-k)){
                hi = p-1;
            }
            if(p<(n-k)){
                lo = p+1; 
            }
        }
        return 0;
    }

    int partition(vector<int>& nums, int lo, int hi){
        int randPivotIndex = lo + rand() % (hi - lo + 1);
        swap(nums, lo, randPivotIndex);  // 随机选择基准
        int i = lo+1, j = hi;
        while(i<=j){
            while(i<hi&&nums[i]<nums[lo]){
                i++;
            }
            while(j>lo&&nums[j]>nums[lo]){
                j--;
            }
            if(i>=j){
                break;
            }
            swap(nums, i, j);
            // int temp = nums[i];
            // nums[i] = nums[j];
            // nums[j] = temp;
        }
        // int temp = nums[lo];
        // nums[lo] = nums[j];
        // nums[j] = temp;
        swap(nums, lo, j);
        return j;
    }

    void swap(vector<int>& nums, int i, int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};