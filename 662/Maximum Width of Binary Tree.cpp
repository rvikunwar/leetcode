// Leetcode - Given the root of a binary tree, return the maximum width of the given tree.
// The maximum width of a tree is the maximum width among all levels.
// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
// It is guaranteed that the answer will in the range of a 32-bit signed integer.

// https://leetcode.com/problems/maximum-width-of-binary-tree/description/

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
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        int maxWidth = INT_MIN;

        while (!q.empty())
        {
            int front = q.front().second;
            int back = q.back().second;
            int levelSize = q.size();
            maxWidth = max(maxWidth, back - front + 1);

            for (int i = 0; i < levelSize; i++)
            {
                auto node_index_pair = q.front();
                TreeNode *node = node_index_pair.first;
                int index = node_index_pair.second - front;
                q.pop();
                if (node->left != NULL)
                {
                    q.push({node->left, 2LL * index + 1});
                }
                if (node->right != NULL)
                {
                    q.push({node->right, 2LL * index + 2});
                }
            }
        }
        return maxWidth;
    }
};