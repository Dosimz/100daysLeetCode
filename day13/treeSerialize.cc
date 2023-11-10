#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 /*
 [1,2,-3,null,null,4,5] : 无法通过，修改代码，遇到负号后往后加一位字符。 未从根本上解决问题
    。。。
 [1,2,-13,null,null,4,5] : 无法通过
 如果在对二叉树进行序列化时，不使用间隔符号，将其转换为字符串后，会无法分辨个位数、十位数、。。。
 */
class Codec {
public:
    void traverseSerialize(TreeNode* node, string& treeStr){
        if(node==nullptr){
            treeStr += "#";
            return;
        }
        treeStr += to_string(node->val);
        // if(node==nullptr){
        //     treeStr += "#.";
        //     return;
        // }
        // treeStr += to_string(node->val) + ".";
        traverseSerialize(node->left, treeStr);
        traverseSerialize(node->right, treeStr);
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string stringTreeList;
        traverseSerialize(root, stringTreeList);
        return stringTreeList;
    }

    TreeNode* decodeBuild(list<string>& nodeArray){
        if(nodeArray.front()=="#"){
            nodeArray.erase(nodeArray.begin());
            return nullptr;
        }
        TreeNode* root;
        if(nodeArray.front()=="-"){
            auto it1 = nodeArray.front();
            nodeArray.erase(nodeArray.begin());
            auto it2 = nodeArray.front();
            nodeArray.erase(nodeArray.begin());
            root = new TreeNode(stoi(it1+it2));
        }else{
            root = new TreeNode(stoi(nodeArray.front()));
            nodeArray.erase(nodeArray.begin());
        }

        root->left = decodeBuild(nodeArray);
        root->right = decodeBuild(nodeArray);
        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        list<string> doubleLinkList;
        string str;
        for(auto &ch: data){
            str.push_back(ch);     // to_string(ch)
            doubleLinkList.push_back(str);
            str.clear();  // 如果不清理会出现 stack-buffer-overflow
        }
        // string str;
        // for (auto& ch : data) {
        //     if (ch == ',') {
        //         doubleLinkList.push_back(str);
        //         str.clear();
        //     } else {
        //         str.push_back(ch);
        //     }
        // }
        // if (!str.empty()) {
        //     doubleLinkList.push_back(str);
        //     str.clear();
        // }

        return decodeBuild(doubleLinkList);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));