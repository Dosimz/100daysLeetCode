#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <numeric>

using namespace std;

class Solution {

public:
    struct NumIndex {
        int val;
        int index;

        bool operator < (const NumIndex &rs) const {
            return val < rs.val;
        }
    };

    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> res(nums1.size());
        int left = 0, right = nums1.size()-1;
        priority_queue<NumIndex> q2;
        for ( int i=0;i<nums2.size();i++ )
            q2.push({nums2[i], i});

        sort(nums1.begin(), nums1.end());
        while ( !q2.empty() )
        {    // 1,10,4,11
            if ( nums1[right]>q2.top().val )
                res[q2.top().index] = nums1[right--];
            else
                res[q2.top().index] = nums1[left++];
            q2.pop();
        }
        return res;
    }
};

class Solution2 {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> idx1(n), idx2(n);
        iota(idx1.begin(), idx1.end(), 0);
        iota(idx2.begin(), idx2.end(), 0);
        sort(idx1.begin(), idx1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });
        sort(idx2.begin(), idx2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });
        
        vector<int> ans(n);
        int left = 0, right = n - 1;
        for (int i = 0; i < n; ++i) {
            if (nums1[idx1[i]] > nums2[idx2[left]]) {
                ans[idx2[left]] = nums1[idx1[i]];
                ++left;
            }
            else {
                ans[idx2[right]] = nums1[idx1[i]];
                --right;
            }
        }
        return ans;
    }
};


int main(){
    Solution2 s;
    vector<int> test1{2,7,11,15};
    vector<int> test2{1,10,4,11};    // 0 2 1 3 
    auto res = s.advantageCount(test1, test2);
    for(auto s: res){
        cout<<s<<endl;
    }
}