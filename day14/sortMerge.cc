#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sort(vector<int>& nums, int lo, int hi) {
        if (lo == hi) return;

        int mid = lo + (hi - lo) / 2;

        sort(nums, lo, mid);
        sort(nums, mid + 1, hi);

        merge(nums, lo, mid, hi);
    }

    void merge(vector<int>& nums, int lo, int mid, int hi) {
        for (int it = lo; it <= hi; it++) {
            temps[it] = nums[it];
        }
        int p = lo; int j = mid + 1;
        for (int i = lo; i <= hi; i++) {
            if (p == (mid + 1)) {
                nums[i] = temps[j++];
            } else if (j == hi + 1) {
                nums[i] = temps[p++];
            } else if (temps[p] < temps[j]) {
                nums[i] = temps[p++];
            } else {
                nums[i] = temps[j++];
            }
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        int lo = 0, hi = nums.size() - 1;
        temps.resize(hi + 1);
        sort(nums, lo, hi);
        return nums;
    }

vector<int> temps;
};
