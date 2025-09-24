/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.
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
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        stack<TreeNode *> stck;
        vector<int> values;
        TreeNode *temp = root;

        while (true)
        {
            while (temp != NULL)
            {
                stck.push(temp);
                temp = temp->left;
            }

            if (stck.empty())
                break;

            temp = stck.top();
            stck.pop();

            values.push_back(temp->val);

            temp = temp->right;
        }

        return values;
    }
};