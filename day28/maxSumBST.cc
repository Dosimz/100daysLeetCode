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
int maxRes= 0;
    int maxSumBST(TreeNode* root) {
        traverse(root);
        return maxRes;
    }
// int[4]
    vector<int> traverse(TreeNode* root){
        if(root==nullptr) {
        return {1, INT_MIN, INT_MAX, 0};
        }
            

        vector<int> left = traverse(root->left);
        vector<int> right = traverse(root->right);
        vector<int> res(4);
        if(left[0]&&right[0]&&root->val>left[1]&&root->val<right[2]){
            res[0] = 1;
            res[1] = max(right[1], root->val);
            res[2] = min(left[2], root->val);
            res[3] = left[3] +right[3] + root->val;

            maxRes = max(maxRes, res[3]);
        }
        else{
            res[0] = 0;
        }
        return res;
    }
 };