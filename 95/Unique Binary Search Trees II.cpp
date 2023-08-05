// Given an integer n, return all the structurally unique BST's (binary search trees), which has exactly n nodes of unique values from 1 to n. Return the answer in any order.

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
    vector<TreeNode *> helper(int start, int end, unordered_map<string, vector<TreeNode *>> &mp)
    {
        if (start > end)
        {
            return {nullptr};
        }

        string s = to_string(start) + "_" + to_string(end);
        if (mp.find(s) != mp.end())
            return mp[s];

        if (start == end)
        {
            mp[s] = {new TreeNode(start)};
            return mp[s];
        }

        vector<TreeNode *> ans;

        for (int i = start; i <= end; i++)
        {

            vector<TreeNode *> vc1 = helper(start, i - 1, mp);
            vector<TreeNode *> vc2 = helper(i + 1, end, mp);

            for (int k = 0; k < vc1.size(); k++)
            {
                for (int j = 0; j < vc2.size(); j++)
                {
                    TreeNode *node = new TreeNode(i);
                    node->left = vc1[k];
                    node->right = vc2[j];
                    ans.push_back(node);
                }
            }
        }
        mp[s] = ans;
        return ans;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        unordered_map<string, vector<TreeNode *>> mp;
        return helper(1, n, mp);
    }
};