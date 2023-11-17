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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==nullptr) return nullptr;
        TreeNode* left = increasingBST(root->left);
        root->left = nullptr;
        TreeNode* right = increasingBST(root->right);
        root->right = right;

        if(left==nullptr) return root;

        TreeNode* p = left;
        while(p->right!=nullptr){
            p = p->right;
        }
        p->right = root;
        return left;
    }

};