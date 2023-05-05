// Leetcode - Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// https://leetcode.com/problems/symmetric-tree/description/

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
        bool isSymmetricNode(TreeNode* left, TreeNode* right){
            if(left == NULL && right == NULL) return true;
            if(left == NULL || right == NULL) return false;
            if(left->val != right->val) return false;
            return isSymmetricNode(left->left, right->right) && isSymmetricNode(left->right, right->left);
        }

        bool isSymmetric(TreeNode* root) {
            if(root == NULL) return false; 
            return isSymmetricNode(root->left, root->right);
        }
};

// class Solution {

//     private:
//         bool isEqual(TreeNode* T1, TreeNode* T2){

//             if(T1 == nullptr && T2 == nullptr) return true;

//             if(T1 == nullptr) return false;

//             if(T2 == nullptr) return false;

//             if(T1->val == T2-> val){
//                 return isEqual(T1->left, T2->right) && isEqual(T1->right, T2->left);
//             }

//             return false;
//         }

//     public:
//         bool isSymmetric(TreeNode* root) {
//             return isEqual(root->left, root->right);
//         }
// };