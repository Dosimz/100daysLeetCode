#include <vector>

class Solution {
public:
    std::vector<int> temps;
    long long count = 0;

    void mergeSort(std::vector<int>& nums, int lo, int hi) {
        if (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            mergeSort(nums, lo, mid);
            mergeSort(nums, mid + 1, hi);

            int j = mid + 1;
            for (int i = lo; i <= mid; i++) {
                while (j <= hi && (long)nums[i] > 2LL * nums[j]) {
                    j++;
                }
                count += j - (mid + 1);
            }

            std::merge(nums.begin() + lo, nums.begin() + mid + 1, nums.begin() + mid + 1, nums.begin() + hi + 1, temps.begin() + lo);
            std::copy(temps.begin() + lo, temps.begin() + hi + 1, nums.begin() + lo);
        }
    }

    int reversePairs(std::vector<int>& nums) {
        if (nums.size() <= 1) {
            return 0;
        }

        temps.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);

        return count;
    }
};
