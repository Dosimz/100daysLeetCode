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
    int maxLevelSum(TreeNode* root) {
        // vector<int> ret;
        int maxindex=0;
        queue<TreeNode*> q;
        q.push(root);
        // int max = 0;      如果有负数，则可能出错
        int max = INT_MIN;
        int level = 1;
        while(!q.empty()){
            int lenOflevel = q.size();
            int sumOflevel = 0;
            for(int i=0; i<lenOflevel; i++){
                auto node = q.front(); q.pop();
                sumOflevel += node->val;

                if(node->left){q.push(node->left);}
                if(node->right){q.push(node->right);}
            }
            // ret.push_back(sumOflevel);

            if(sumOflevel>max){
                max = sumOflevel;
                maxindex = level;
            }
            level++;
        }
        return maxindex;
    }
};

int main(){
     // Example binary tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    // [-100,-200,-300,-20,-5,-10,null]
    TreeNode* root = new TreeNode(-100,
        new TreeNode(-200, new TreeNode(-20), new TreeNode(-5)),
        new TreeNode(-300, new TreeNode(-10), nullptr)
    );   
    
    Solution s;
    auto res = s.maxLevelSum(root);
    cout<<res<<endl;
    return 1;
}