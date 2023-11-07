#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}};

class Solution {
public:
    int depth = 0;
    int dDep = 0;
    int traverse(TreeNode* node){
        if(node==nullptr){
            return 0;
        }
        dDep++;
        traverse(node->left);
        traverse(node->right);
        if(node->left==nullptr&&node->right==nullptr)
            depth = dDep > depth ? dDep : depth;
        dDep--;
        return 1;
    }

    int maxDepth(TreeNode* root) {
        traverse(root);      
        return depth;
    }
};