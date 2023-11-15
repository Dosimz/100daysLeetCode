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


class CBTInserter {
public:
    TreeNode* rootN;
    CBTInserter(TreeNode* root) {
        rootN = root;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(rootN);
        int res;
        while(!q.empty()){
            int lenOflevel = q.size();
            for(int i=0; i<lenOflevel; i++){
                auto node = q.front(); q.pop();
                if(node->left){
                    q.push(node->left);
                }else{
                    node->left = new TreeNode(val);
                    res = node->val;
                    return node->val;
                }
                if(node->right){
                    q.push(node->right);
                }else{
                    node->right = new TreeNode(val);
                    res = node->val;
                    return node->val;
                }
            }
        }
        return res;
    }
    
    TreeNode* get_root() {
        return rootN;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */