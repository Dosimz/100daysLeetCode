#include <iostream>
#include <vector>
#include <queue>
#include <deque>
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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int leftHigh = 1;
        int rightHigh = 1;
        TreeNode* l = root->left;
        TreeNode* r = root->right;
        while(l!=nullptr){
            l = l->left;
            leftHigh++;
        }

        while(r!=nullptr){
            r = r->right;
            rightHigh++;
        }
        
        if(leftHigh==rightHigh){
            return (pow(2, leftHigh)-1);
        }

        return 1+countNodes(root->left)+countNodes(root->right);
    }
};