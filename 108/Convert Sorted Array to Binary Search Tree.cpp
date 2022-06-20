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
    
    TreeNode*  buildTree(vector<int> nums, int low, int high){
        if(low >= high){
            return nullptr;
        }
        int mid = (high + low)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = buildTree(nums, low, mid);
        temp->right = buildTree(nums, mid+1, high);
        return temp;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0){
            return nullptr;
        }
        int low = 0;
        int high = nums.size();
        int mid = (high + low)/2;
        TreeNode* temp = new TreeNode(nums[mid]);
        temp->left = buildTree(nums, low, mid);
        temp->right = buildTree(nums, mid+1, high);
        return temp;
    }
};
