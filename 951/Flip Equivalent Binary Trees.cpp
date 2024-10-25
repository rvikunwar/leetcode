// Flip Equivalent Binary Trees.cpp
// https://leetcode.com/problems/flip-equivalent-binary-trees/?envType=daily-question&envId=2024-10-24

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
    bool preOrder(TreeNode* node1, TreeNode* node2) {
        if(node1 == nullptr && node2 == nullptr) return true;
        if(node1 == nullptr || node2 == nullptr) return false;
        if(node1->val != node2->val) return false;

        return ((
                preOrder(node1->left, node2->left) || 
                preOrder(node1->left, node2->right)
            )) 
            && 
            ((
                preOrder(node1->right, node2->left) ||
                preOrder(node1->right, node2->right)
            ));
    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return preOrder(root1, root2);
    }
};
