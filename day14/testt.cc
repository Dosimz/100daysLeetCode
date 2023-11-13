#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct pair {
        int id;
        int val;
        pair(int idd, int vall) {
            id = idd;
            val = vall;
        };
        pair() {
            id = 0;
            val = 0;
        }
    };
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
        nTp.resize(hi+1);
        // vector<pair> nTp(hi+1);    //(hi+1)
        for (int t = 0; t <= hi; t++) {
            // nTp.push_back(pair(t, nums[t])); ??
            nTp[t] = pair(t, nums[t]);
            
        }

        sort(nums, lo, hi);
        return nums;
    }

vector<int> temps;
unordered_map<int, int> count;
vector<pair> nTp;
};


int main() {
    Solution solution;

    // Test case 1
    vector<int> nums = {5, 2, 6, 3, 1};
    // vector<int> expected = {4, 0, 1, 1, 0};
    vector<int> expected = {1, 2, 3, 5, 6};
    vector<int> actual = solution.sortArray(nums);
    if (expected == actual) {
        cout << "Test case 1 passed." << endl;
    } else {
        cout << "Test case 1 failed." << endl;
    }
}