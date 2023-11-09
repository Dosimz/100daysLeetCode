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
    unordered_map<int, int> valueIndex;
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        for(int i=0; i<preorder.size(); i++){
            valueIndex[preorder[i]] = i;
        }
        return build(preorder, 0, preorder.size()-1, postorder, 0, postorder.size()-1);
    }

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd, vector<int>& postorder, int postStart, int postEnd){
        if(postStart>postEnd) return nullptr;
        if (postStart == postEnd) {
            return new TreeNode(preorder[preStart]);
        }

        int rootVal = postorder[postEnd];
        int rightVal = postorder[postEnd-1];
        int index = valueIndex[rightVal];

        TreeNode* root = new TreeNode(rootVal);
        
        root->left = build(preorder, preStart+1, index-1, postorder, postStart, postStart+index-1-preStart-1);
        root->right = build(preorder, index, preEnd, postorder, postEnd-1-preEnd+index, postEnd-1);

        return root;
    }
};