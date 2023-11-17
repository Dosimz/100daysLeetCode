#include <iostream>
#include <vector>
#include <queue>
#include <deque>
using namespace std;


class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    // int itDepth=0;
    // int maxDepth=0;
    int maxDepth(Node* root) {
        if(root==nullptr) return 0;
        int subTreeMaxDeepth = 0;
        for(auto it: root->children){
            // itDepth = maxDepth(it);
            // maxDepth = maxDepth > itDepth ? maxDepth : itDepth;
            subTreeMaxDeepth = max(subTreeMaxDeepth, maxDepth(it));
        }
        return subTreeMaxDeepth+1;
    }
};