#include <iostream>
#include <vector>

using namespace std;

struct Difference
{
    vector<int> diff;

    Difference(vector<int>& nums){
        diff.resize(nums.size());
        diff[0] = nums[0];
        for(int i=1; i<diff.size(); i++){
            diff[i] = nums[i] - nums[i-1];
        }
    }

    void increment(int start, int end, int val){
        diff[start] += val;
        if(end<diff.size()-1)
            diff[end+1] -=val;
    }

    vector<int> result(){
        vector<int> result(diff.size());
        result[0] = diff[0];
        for(int i=1; i<diff.size(); i++){
            result[i] = result[i-1] + diff[i];
        }
        return result;
    }
};



vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
    // nums 初始化为全 0
    vector<int> nums(length, 0);
    // 构造差分解法
    Difference df(nums);
    
    for (auto update : updates) {
        int i = update[0];
        int j = update[1];
        int val = update[2];
        df.increment(i, j, val);
    }
    
    return df.result();
}

int main(){
    vector<vector<int>> updates = {{1,3,2},{2,4,3},{0,2,-2}};
    vector<int> res = getModifiedArray(5, updates);
    for(auto i:res){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}