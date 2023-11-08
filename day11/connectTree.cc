/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
#include <iostream>
#include <vector>

using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==nullptr) return root;
        TraverseThree(root->left, root->right);
        return root;
    }

    void TraverseThree(Node* node1, Node* node2){
        if(node1==nullptr||node2==nullptr) return;
        TraverseThree(node1->left, node1->right);
        TraverseThree(node2->left, node2->right);

        TraverseThree(node1->right, node2->left);      
        if(node1!=nullptr&&node2!=nullptr)
            node1->next = node2;
    }
};