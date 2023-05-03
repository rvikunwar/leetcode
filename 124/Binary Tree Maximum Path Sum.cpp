// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

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
    int maxSum(TreeNode *node, int &sum)
    {
        if (node == NULL)
            return 0;
        int sl = maxSum(node->left, sum);
        int sr = maxSum(node->right, sum);
        sl = sl >= 0 ? sl : 0;
        sr = sr >= 0 ? sr : 0;
        sum = max(sl + sr + node->val, sum);
        return max(sl, sr) + node->val;
    }

public:
    int maxPathSum(TreeNode *root)
    {
        int sum = INT_MIN;
        maxSum(root, sum);
        return sum;
    }
};