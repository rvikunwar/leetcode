// Leetcode - Given the root of a binary tree, return the preorder traversal of its nodes' values.

// Input: root = [1,null,2,3]
// Output: [1,2,3]

// https://leetcode.com/problems/binary-tree-preorder-traversal/description/

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
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (root == NULL)
            return {};
        stack<TreeNode *> st;
        vector<int> ans;
        st.push(root);
        while (!st.empty())
        {
            TreeNode *top = st.top();
            st.pop();
            ans.push_back(top->val);
            if (top->right != NULL)
                st.push(top->right);
            if (top->left != NULL)
                st.push(top->left);
        }
        return ans;
    }
};