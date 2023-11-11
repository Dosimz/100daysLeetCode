#include <iostream>
#include <vector>

using namespace std;


// Definition for a Node.
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
    vector<int> res;

    void travserse(Node* node){
        if(node==nullptr) return;
        for(auto it: node->children){
            postorder(it);
        }
        res.push_back(node->val);
        return;
    }

    vector<int> postorder(Node* root) {
        travserse(root);
        return res;
    }
};