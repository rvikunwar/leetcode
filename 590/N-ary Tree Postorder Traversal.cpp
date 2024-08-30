// N-ary Tree Postorder Traversal.cpp

/*
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
*/

class Solution {
public:
    void helper(Node* node, vector<int> &ans) {
        if(node == nullptr) {
            return;
        }

        for(auto it: node->children) {
            helper(it, ans);
        }
        ans.push_back(node->val);
    }

    vector<int> postorder(Node* root) {
        vector<int> ans;      
        helper(root, ans);
        return ans;
    }
};