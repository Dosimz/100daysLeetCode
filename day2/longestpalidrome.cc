#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:


 string palindrome(string &s, int le, int rig){
        while(le>=0 && rig<s.size()){
            if (s[le]==s[rig]){
                le--;
                rig++;
            } else {
                break;
            }
        }
        return s.substr(le+1, rig-le-1);
    }
    string longestPalindrome(string s) {
        string res = "";
        for (int i=0; i<s.size(); i++){
            string s1 = palindrome(s, i, i);
            string s2 = palindrome(s, i, i+1);

            res = res.size() > s1.size() ? res : s1;
            res = res.size() > s2.size() ? res : s2;
        }
        return res;
    }

};
//  string palindrome(string &s, int le, int rig){
//         int s_le = le;
//         int s_rig = rig;
//         while(le < rig){
//             if(s[le] == s[rig]){
//                 le++;
//                 rig--;
//             }
//             else {
//                 string leStr = palindrome(s, ++s_le, s_rig);
//                 string rigStr = palindrome(s, s_le, --s_rig);
//                 if (leStr.size() > rigStr.size())
//                     return leStr;
//                 else 
//                     return rigStr;
//             }
//         }
//         return s.substr(s_le, s_rig-s_le+1);
//     }
//  string longestPalindrome(string s) {
//         int left = 0; int right = s.size() -1;        
//         string res = palindrome(s, left, right);
//         return res;
//     }

// };

int main(){
    Solution s;
    string str = "babd";
    string res = s.longestPalindrome(str);
    cout << res << endl;
    return 0;
}