#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
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


    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int first = 0;
        int last = 0;
        int e_num = 0;
        int record = bookings.size();
        
        vector<int> answer(n, 0);
        Difference diff = Difference(answer);

        for(int i=0; i<record; i++){
            first = bookings[i][0] - 1;
            last = bookings[i][1] -1;
            e_num = bookings[i][2];
            diff.increment(first, last, e_num);
        }

        return diff.result();

    
    }
};