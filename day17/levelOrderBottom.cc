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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lenOflevel = q.size();
            auto level = vector<int>();
            for(int i=0; i<lenOflevel; i++){
                auto node = q.front();  q.pop();
                level.push_back(node->val);
                if(node->left) {
                  q.push(node->left);
                }
                if(node->right) {
                  q.push(node->right);
                }
            }
            ret.push_back(level);
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};