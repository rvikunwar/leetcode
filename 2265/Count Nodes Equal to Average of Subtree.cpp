// Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.

// Note:

// The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
// A subtree of root is a tree consisting of root and all of its descendants.


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
    pair<int, int> postTravesal(TreeNode *node, int& ans){
        if(node == nullptr) return { 0, 0 };
        pair<int, int> left = postTravesal(node->left, ans);
        pair<int, int> right = postTravesal(node->right, ans);
        int sum = node->val + left.first + right.first;
        int counts = left.second + right.second + 1;
        int avg = sum/counts;
        if(avg == node->val) {
            ans++;
        }
        return { sum, counts };
    }
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr) return 0;
        int ans = 0;
        postTravesal(root, ans);
        return ans;
    }
};