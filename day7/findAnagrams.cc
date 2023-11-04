#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> winodw, need;
        int left =0, right=0;
        int valid= 0;

        for(auto cc: p) need[cc]++;

        vector<int> nums;

        while(right<s.size()){
            char c = s[right++];
            
            if(need.count(c)){
                winodw[c]++;
                if(winodw[c]==need[c])
                    valid++;
            }
            while(right-left>=p.size()){
                if(valid==need.size()){
                    nums.push_back(left);
                }
                char c2 = s[left++];
                if(need.count(c2)){
                    if(winodw[c2]==need[c2])
                        valid--;
                    winodw[c2]--;
                }
            }
        }
        return nums;
    }
};