#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left= 0, right=0;
        int index = 0;
        unordered_map<char, int> window;
        if (s.size()==0) return 0;
        int len= 1;
        while(right<s.size()){
            char c = s[right++];
            window[c]++;

            while(window[c]>1){
                char cc = s[left++];
                window[cc]--;
            }
        if(right-left>len)
            len = right-left;
        }
        return len;
    }
};