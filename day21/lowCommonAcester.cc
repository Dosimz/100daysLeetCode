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


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return nullptr;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if(root==q||root==p){return root;}
            if(left!=nullptr&&right!=nullptr){
           return root;
       }

       // 这条语句必须放在最前面，因为后面的  left!=nullptr || right != nullptr 的条件包含了当前条件
        if(left!=nullptr||right!=nullptr){
            return left == nullptr ? right : left;
        }
        if(left==nullptr&&right==nullptr){return nullptr;}
    

        return nullptr;
    }
};