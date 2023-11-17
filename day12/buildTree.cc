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
#include <iostream>
#include <vector>

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0, end = inorder.size()-1;
        int pre_start = 0, pre_end = preorder.size()-1;
        TreeNode* node = build(preorder, pre_start, pre_end, inorder, start, end);
        return node;
    }
             
    TreeNode* build(vector<int> preorder, int pre_start, int pre_end, vector<int> inorder, int start, int end){
        if(start>end) return nullptr;
        int index = 0;
        TreeNode* root = new TreeNode(preorder[pre_start]);
        for(int j=start; j<=end; j++){
            if(inorder[j]==preorder[pre_start]){
                index = j;
                break;        
            }
        }

        root->left = build(preorder,pre_start+1,pre_start+index-start, inorder, start, index-1);
        root->right = build(preorder,pre_start+index-start+1, pre_end, inorder, index+1, end);

        return root;
    }
};