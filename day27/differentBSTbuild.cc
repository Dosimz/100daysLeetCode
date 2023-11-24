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
    vector<TreeNode*> generateTrees(int n) {
        return build(1, n);
    }

    vector<TreeNode*> build(int lo, int hi){
        vector<TreeNode*> res;
        if(lo>hi) {
            res.push_back(nullptr);
            return res;
        }

        for(int mid=lo; mid<=hi; mid++){
            vector<TreeNode*> left = build(lo, mid-1);
            vector<TreeNode*> right = build(mid+1, hi);

            for(auto ll:left){
                for(auto rr: right){
                    TreeNode* root = new TreeNode(mid);
                    root->left = ll;
                    root->right = rr;
                    res.push_back(root);
                }
            }
        }

        return res;
    }
};