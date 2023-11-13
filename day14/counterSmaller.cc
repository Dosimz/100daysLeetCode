#include <iostream>
#include <vector>

using namespace std;

class Solution {


public:
    struct pair{
        int id;
        int val;
        pair(int idd, int vall){
            id  = idd;
            val = vall;
        };
        pair(){
            id =0;
            val = 0;
        }
    };
    vector<pair> temps;
    unordered_map<int, int> count;
   
    void mergeSort(vector<pair>& pairs, int lo, int hi){
        if(lo==hi) return;
        int mid = lo + (hi-lo)/2;

        mergeSort(pairs, lo, mid);
        mergeSort(pairs, mid+1, hi);
        
        for (int it = lo; it <= hi; it++) {
            temps[it] = pairs[it];  // .val
        }

        int i = lo, j = mid+1;
        for(int p=lo; p<=hi; p++){
            if(i==mid+1){
                pairs[p] = temps[j++];
                }
            else if(j==hi+1){
                pairs[p] = temps[i++];
                count[pairs[p].id] += j -mid-1;
                }
            else if(temps[i].val>temps[j].val){
                 pairs[p] = temps[j++];
            }else{
                pairs[p] = temps[i++];
                count[pairs[p].id] += j -mid-1;
            }
        }
        return;
    }

    vector<int> countSmaller(vector<int>& nums) {
        temps.resize(nums.size());
        // temps = nums;
        vector<pair> nTp;      //(nums.size());
        for(int t=0; t<nums.size(); t++){
            nTp.push_back(pair(t,nums[t]));
        }
        int lo = 0, hi = nums.size()-1;
        mergeSort(nTp, lo, hi);
        vector<int> res(nums.size());
        for(int intemp=0; intemp<nums.size(); intemp++){
            res[intemp] = count[intemp];
        }
        return res;
    }
};  

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums = {5, 2, 6, 3, 1};
    vector<int> expected = {3, 1, 2, 1, 0};
    vector<int> actual = solution.countSmaller(nums);
    if (expected == actual) {
        cout << "Test case 1 passed." << endl;
    } else {
        cout << "Test case 1 failed." << endl;
    }

    // // Test case 2
    // nums = {2, 0, 1};
    // expected = {0, 0, 1};
    // actual = solution.countSmaller(nums);
    // if (expected == actual) {
    //     cout << "Test case 2 passed." << endl;
    // } else {
    //     cout << "Test case 2 failed." << endl;
    // }

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
