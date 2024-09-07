// Linked List in Binary Tree.cpp

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    bool helper(TreeNode* tree_node, ListNode* list_node) {
        if(list_node == nullptr) return true; 
        if(tree_node == nullptr) return false;

        if(tree_node->val == list_node->val) {
            list_node = list_node->next;
        } else {
            return false;
        }

        return helper(tree_node->left, list_node) || helper(tree_node->right, list_node);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == nullptr) return false;
        if(helper(root, head)) return true;
        return isSubPath(head, root->left) || isSubPath(head, root->right);      
    }
};