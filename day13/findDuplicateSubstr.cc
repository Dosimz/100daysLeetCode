#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return {repeat.begin(), repeat.end()};
    }

    string dfs(TreeNode * node){
        if(node==nullptr)
            return "";
        
        string serial = to_string(node->val) + "(" + dfs(node->left) + ")(" + dfs(node->right) + ")";
        if (auto it = seen.find(serial); it != seen.end()) {
            repeat.insert(it->second);
        }
        else {
            seen[serial] = node;
        }
        return serial;

    }

private:
    unordered_map<string, TreeNode*> seen;
    unordered_set<TreeNode*> repeat; 

};