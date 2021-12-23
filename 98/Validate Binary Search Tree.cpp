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
    stack<int> st;
    bool val = true;
    bool isValidBST(TreeNode* root) {
        
        if(root == nullptr){
            return true;
        }
        
        val = isValidBST(root->left);
        
        if(val == false){
            return false;
        }
        
        if(st.empty()){
            st.push(root->val);
        } else {
            if(st.top()<root->val){
                st.push(root->val);
            } else {
                return false;
            }
        }
        
        val = isValidBST(root->right);
        return val;
        
    }
};