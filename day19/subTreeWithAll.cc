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
    struct NodeDep{
        TreeNode* node;
        int depth;

        NodeDep(TreeNode* n, int d){
            node = n;
            depth = d;
        }
    };

    NodeDep maxDepth(TreeNode* node){
        if(node==nullptr) return NodeDep(nullptr, 0);
        NodeDep left = maxDepth(node->left);
        NodeDep right = maxDepth(node->right);

        if(left.depth == right.depth){
            return NodeDep(node, left.depth+1);
        }

        auto res = left.depth >right.depth ? left : right;
        res.depth++;
        return res;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        auto res = maxDepth(root);
        return res.node;
    }
};

class Solution { 
public:
    int depth=0;
    int maxDepth=0;
    vector<TreeNode*> q;
    void traverse(TreeNode* node){
        if(node==nullptr) return;
        depth++;   
        if(maxDepth<=depth){
            maxDepth = depth;
            q.push_back(node);
        }

        traverse(node->left);
        traverse(node->right);
        depth--;
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if(root==nullptr) return nullptr;
        traverse(root);
        return q[-2];
    }
};