#include <iostream>
#include <unordered_set>


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

    unordered_set<int> ss;
    bool ssss = true;
    bool isUnivalTree(TreeNode* root) {
        traverse(root);
        return ssss;
    }
        void traverse(TreeNode* root){
        if(root==nullptr) return;
        ss.insert(root->val);
        if(ss.size()>1){ssss= false;}

        traverse(root->left);
        traverse(root->right);
    }
};