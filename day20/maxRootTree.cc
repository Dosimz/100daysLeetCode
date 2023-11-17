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
    
    TreeNode* build(vector<int>& nums, int start ,int end){
        if(start>end) return nullptr;
        int index=0;
        int maxtemp=0;   // stack overflow
        for(int i=start; i<=end; i++){
            if(maxtemp<nums[i]){
                maxtemp = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(maxtemp);
        node->left = build(nums, start, index-1);
        node->right = build(nums, index+1, end);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int end = nums.size()-1;
        return build(nums, 0, end);
    }
};

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
    
    TreeNode* build(vector<int>& nums, int start ,int end){
        if(start>end) return nullptr;
        int index=-1;
        int maxtemp=std::numeric_limits<int>::min();
        for(int i=start; i<=end; i++){
            if(maxtemp<nums[i]){
                maxtemp = nums[i];
                index = i;
            }
        }
        TreeNode* node = new TreeNode(maxtemp);
        node->left = build(nums, start, index-1);
        node->right = build(nums, index+1, end);
        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int end = nums.size()-1;
        return build(nums, 0, end);
    }
};
int main() {
    Solution solution;
    vector<int> nums;
    TreeNode* result;

    // Test Case 1
    nums = {5};
    result = solution.constructMaximumBinaryTree(nums);
    // Print or validate the result

    // Test Case 2
    nums = {1, 2, 3, 4, 5};
    result = solution.constructMaximumBinaryTree(nums);
    // Print or validate the result

    // and so on for other test cases...
}
