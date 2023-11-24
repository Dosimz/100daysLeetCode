#include <iostream>
#include <vector>

using namespace std;

class Solution{
    // 定义树节点结构
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };

    bool isValidPreorder(vector<int>& preorder){
        int n = preorder.size()-1;
        return check(preorder, 0, n, INT_MIN, INT_MAX);
    }

    bool check(vector<int>& preoder, int start, int end, int min, int max){
        int rootVal = preoder[start];
        if(rootVal<min||rootVal>max){
            return false;
        }
        int p = start+1; 
        while(preoder[p]<rootVal){
            p++;
        }

        return check(preoder, start+1, p-1, min, rootVal)&&check(preoder, p, end, rootVal, max);
    }
};