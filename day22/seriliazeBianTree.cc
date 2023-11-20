class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        serialize(root, s);
        return s;
    }

    void serialize(TreeNode* root, string& s) {
        if (root == nullptr) {
            s += "null,";
            return;
        }

        s += to_string(root->val) + ",";
        serialize(root->left, s);
        serialize(root->right, s);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty()) return nullptr;

        queue<string> nodes;
        string str;
        for (char ch : data) {
            if (ch == ',') {
                nodes.push(str);
                str.clear();
            } else {
                str.push_back(ch);
            }
        }
        if (!str.empty()) {
            nodes.push(str);
        }

        return deserialize(nodes, INT_MIN, INT_MAX);
    }

private:
    TreeNode* deserialize(queue<string>& nodes, int lower, int upper) {
        if (nodes.empty()) {
            return nullptr;
        }

        string val = nodes.front();
        if (val == "null") {
            nodes.pop();
            return nullptr;
        }

        int rootVal = stoi(val);
        // if (rootVal < lower || rootVal > upper) {
        //     return nullptr;
        // }

        nodes.pop();
        TreeNode* root = new TreeNode(rootVal);
        root->left = deserialize(nodes, lower, rootVal);
        root->right = deserialize(nodes, rootVal, upper);
        return root;
    }
};
