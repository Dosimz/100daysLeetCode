#include <iostream>
#include <vector>

using namespace std;


// Definition for a binary tree node.
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

    TreeNode* dfs(TreeNode* node, int target){
        if(node==nullptr) return nullptr;
        TreeNode* left =  dfs(node->left, target);
        TreeNode* right = dfs(node->right, target);
        node->left = left;
        node->right = right;
        if(left==nullptr&&right==nullptr&&node->val==target){
            return nullptr;
        }

        return node;

    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        TreeNode* res = dfs(root, target);
        if(res==nullptr) return nullptr;
        if(res->left==nullptr&&res->right==nullptr&&res->val==target){
            return nullptr;
        }
        return root;
    }
};




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
class Solution {
public:


    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        // TreeNode* res = dfs(root, target);
        if(root==nullptr) return nullptr;
        
        auto left = removeLeafNodes(root->left, target);
        auto right = removeLeafNodes(root->right, target);

        root->left = left;
        root->right = right;

        if(root->left==nullptr&&root->right==nullptr&&root->val==target){
            return nullptr;
        }
        return root;
    }
};