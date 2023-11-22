class Solution {
public:
    void traverse(TreeNode* node, int k){
        if(node==nullptr) return;
        traverse(node->left, k);
        ++rank;

        if(rank==k){
            res = node->val;
            return;
        }
        traverse(node->right, k);
    }


        int res = 0;
        int rank = 0;
    int kthSmallest(TreeNode* root, int k) {
        traverse(root, k);
        return res;
    }
};