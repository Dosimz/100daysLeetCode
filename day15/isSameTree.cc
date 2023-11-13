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
    std::unordered_map<std::string, int> map;

    std::string traverse(TreeNode* root) {
        if (root == nullptr) {
            return "#";
        }

        std::string s = "(" + traverse(root->left) + to_string(root->val) + traverse(root->right) + ")";
        map[s]++;
        return s;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        std::string s1 = traverse(p);
        std::string s2 = traverse(q);
        // return s1==s2;
        return map[s1] > 1 && map[s2] > 1;
    }
};