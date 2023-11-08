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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* res = build(nums, 0, nums.size()-1);
        return res;
    }

    TreeNode* build(vector<int> nums, int start, int end){

        // if(start<0||end>nums.size()-1) return nullptr;
        if(start>end) return nullptr;
        int maxIndex = 0; 
        int maxValue = INT_MIN;
        for(int i=start; i<=end; i++){
            if(nums[i]>maxValue){
                maxValue = nums[i];            
                maxIndex = i;
            }
        }

        TreeNode *node =  new TreeNode(maxValue);

        node->left = build(nums, start, maxIndex-1);
        node->right = build(nums, maxIndex+1, end);

        return node;


    }


};