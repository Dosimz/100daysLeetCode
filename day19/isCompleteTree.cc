#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};




class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        bool isTrue = true;
        if(root==nullptr) return isTrue;
        queue<TreeNode*> q;
        vector<int> p;
        q.push(root);
        while(!q.empty()){
            int lenOflevel = q.size();
            auto node = q.front(); q.pop();
            if(node==nullptr){
                break;
            }          
            q.push(node->left);
            q.push(node->right);
        }
        while(!q.empty()){
            auto node = q.front(); q.pop();
            if(node){
                return false;
            }
        }
        return isTrue;
    }
};