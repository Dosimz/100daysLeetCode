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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr) return ret;
        queue<TreeNode*> q;
        q.push(root);
        bool flag = true;
        while(!q.empty()){
        //   ret.push_back(std::vector<int>());   
          int tempLen = q.size();
          deque<int> templist;
          for(int i=0; i<tempLen; i++){
            auto node = q.front(); q.pop();
            // ret.back().push_back(node->val);
            if(flag){
              templist.push_back(node->val);
            }else {
              templist.push_front(node->val);
            }
            if(node->left){q.push(node->left);} 
            if(node->right){q.push(node->right);}   
          }

          ret.emplace_back(vector<int>{templist.begin(), templist.end()});
          flag = flag==true ? false:true;
        }
        return ret;
    }
};

int main() {
    // Example binary tree:
    //         1
    //        / \
    //       2   3
    //      / \ / \
    //     4  5 6  7
    TreeNode* root = new TreeNode(1,
        new TreeNode(2, new TreeNode(4), new TreeNode(5)),
        new TreeNode(3, new TreeNode(6), new TreeNode(7))
    );

    Solution s;
    vector<vector<int>> result = s.zigzagLevelOrder(root);

    // Display the result
    for (const auto& level : result) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Don't forget to free the allocated memory
    // You may use a function to delete the tree nodes recursively
    // or use an appropriate mechanism depending on your actual implementation.

    return 0;
}
