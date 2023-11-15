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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int lenOflevel = q.size();
            double avgOflevel = 0;
            for(int i=0; i<lenOflevel; i++){
                auto node = q.front(); q.pop();
                avgOflevel += node->val;
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            double temp =  avgOflevel / lenOflevel;
            res.push_back(temp);
        }
        return res;
    }
};