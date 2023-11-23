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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr) return nullptr;
        if(root->val == key){
            if(root->left==nullptr){
                return root->right;
            }
            if(root->right==nullptr){
                return root->left;
            }
            if(root->left&&root->right){
                TreeNode* minNode = getMin(root->right);
                root->right = deleteNode(root->right, minNode->val);
                minNode->left = root->left;
                minNode->right = root->right;
                root = minNode;
                return root;
            }
        }

        if(root->val > key){
            root->left =  deleteNode(root->left, key);
        }
        if(root->val < key){
            root->right =  deleteNode(root->right, key);
        }

        return root;

    }

    TreeNode* getMin(TreeNode* root){
        while(root->left!=nullptr){
            root = root->left;
        }
        return root;
    }
};