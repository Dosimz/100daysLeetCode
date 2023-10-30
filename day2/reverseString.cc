#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0; int right = s.size()-1;
        char exv;
        while(left<right){
            exv = s[left];
            s[left] = s[right];
            s[right] = exv;
            left++;
            right--;
        }
    }
};