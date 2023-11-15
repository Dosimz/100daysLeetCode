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
    bool isEvenOddTree(TreeNode* root) {
        bool res=false;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int tempval = -1;
            int lenOflevel = q.size();
            for(int i=0; i< lenOflevel; i++){
                auto node = q.front(); q.pop();
                node->val;
                if(level==0&&(node->val %2) == 1){
                        res = true;
                }
                else if((level%2)==1){
                    if(tempval!=-1&&tempval<=node->val||(node->val%2)==1){
                        return false;
                    }
                    tempval = node->val;
                }else if((level%2)==0&&level!=0){
                    if(tempval>=node->val&&tempval!=-1||(node->val%2)==0){
                        return false;
                    }
                    tempval = node->val;
                }else{
                    return false;
                }
                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            level++;  
        }
        return res;
    }
};