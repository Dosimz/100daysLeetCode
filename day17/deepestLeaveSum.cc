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
    int deepestLeavesSum(TreeNode* root) {
        int res=0;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lenOflevel = q.size();
            int sumOflevel=0;
            for(int i=0; i<lenOflevel; i++){
                auto node = q.front(); q.pop();
                sumOflevel += node->val;
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            res =sumOflevel;
        }
        return res;
    }
};