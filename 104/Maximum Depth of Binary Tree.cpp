// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

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

    int traverse(TreeNode* node){
        if(node == NULL){
            return 0;
        }

        int depth = 1 + max(traverse(node->left), traverse(node->right));
        return depth;
    }

    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int depth = 1 + max(traverse(root->left), traverse(root->right));

        return depth;
    }
};