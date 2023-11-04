#include <iostream>
#include <vector>

using namespace std;
 


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> window, need;
        int left = 0, right = 0;
        int valid = 0;
        for(auto cc: s1) need[cc]++;

        while(right<s2.size()){
            char c = s2[right];
            right++;
            if(need.count(c)){
                window[c]++;
                if(window[c]==need[c])
                    valid++;
            }
            while(right-left>=s1.size()) {
                if(valid==need.size())
                    return true;
                char s = s2[left++];
                if(need.count(s)){
                    if(window[s]==need[s])
                        valid--;
                    window[s]--;
                }

            }
        }
        return false;
    }
};