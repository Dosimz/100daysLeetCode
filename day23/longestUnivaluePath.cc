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
int res;
    int dfsUnivalue(TreeNode* node){
        if(node==nullptr) return 0;
        int left = dfsUnivalue(node->left);
        int right = dfsUnivalue(node->right);

        int left1 =0, right1 = 0;
        // 只有相同时，才将 左右子树🌲的 maxUniValue 传递到  
        if(node->left&&node->val==node->left->val){
            // left += 1;        
            left1 = left + 1;
        }
        if(node->right&&node->val==node->right->val){
            // right += 1;
            right1 = right + 1;
        }

        res = max(res, left1+right1);

        return max(left1, right1);     
    }    

    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        dfsUnivalue(root);
        return res;
    }
};

int main(){
    TreeNode* root5 = new TreeNode(5);
    root5->left = new TreeNode(4);
    root5->right = new TreeNode(5);
    root5->left->left = new TreeNode(1);
    root5->left->right = new TreeNode(1);
    root5->right->right = new TreeNode(5);


    Solution s;

    // s.longestUnivaluePath();
    cout << "Test Case 5: " << s.longestUnivaluePath(root5) << endl;
    
}