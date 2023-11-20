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
    int maxSuu=INT_MIN;

    int maxGain(TreeNode* root){
        if(root==nullptr) return 0;
        int left = max(maxGain(root->left), 0);
        int right = max(maxGain(root->right), 0);
        int maxPathS = left + right + root->val;        
        maxSuu = max(maxSuu, maxPathS);
        return max(left, right) + root->val;
    }

    int maxPathSum(TreeNode* root) { 
        maxGain(root);
        return maxSuu;
    }
};