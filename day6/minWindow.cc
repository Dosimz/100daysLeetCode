#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> window, needs;
        int left=0, right = 0;
        int valid = 0;
        int start = 0;
        int minString = INT_MAX;

        for(auto tt: t){
            needs[tt]++;
        }

        while(right<s.size()){
            char c = s[right];
            right++;
            if(needs.count(c)){
                window[c]++;
                if(window[c]==needs[c]){
                    valid++;  
                }
            }
            while(left<right&&valid==needs.size()){
                if(right-left<minString){
                    start = left;
                    minString = right-left;
                }
                char d = s[left++];
                if(window.count(d)){
                    if(needs[d]==window[d]){
                        valid--;
                    }
                window[d]--;
                }

            }
        }
        return minString == INT_MAX ? "" : s.substr(start, minString);

    }
};

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution ss;
    string answer = ss.minWindow(s, t);
    cout<<answer<<endl;
    return 0;
}