### *Issues*

TreeNode* node = TreeNode(val);   // 报错

TreeNode* node = new TreeNode(val);   // 不报错

In summary, the first line attempts to assign a pointer to a stack-allocated temporary object, which is not allowed, while the second line correctly allocates memory on the heap and assigns its address to the pointer.

```cpp
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1);
        
    }

    TreeNode* build(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int start, int end){
        if(start>end) return nullptr;
        int index = 0;
        int rootVal = preorder[pre_start];
        TreeNode* root = new TreeNode(rootVal);
        for(int j=0; j<=end; j++){
            if(inorder[j]==rootVal){
                index = j;
                break;        
            }
        }
        
        root->left = build(preorder,pre_start+1,pre_start+index-start, inorder, start, index-1);
        root->right = build(preorder,pre_start+index-start+1, pre_end, inorder, index+1, end);

        return root;
    }
};
```

在该代码中，`build` 函数如果不使用 `vector<int>&` 引用，运行时间提升近一半。为什么？