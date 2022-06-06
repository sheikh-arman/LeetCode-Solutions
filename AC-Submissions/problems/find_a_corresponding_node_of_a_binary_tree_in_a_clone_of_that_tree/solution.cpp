/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution
{
public:
    TreeNode* ans=new TreeNode();
    void sol(TreeNode* root, TreeNode* target)
    {
        if(root->val==target->val)
        {
            ans=root;
            return;
        }
        if(root->left!=NULL)
        {
            sol(root->left,target);
        }
        if(root->right!=NULL)
        {
            sol(root->right,target);
        }
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target)
    {
        sol(cloned,target);
        return ans;
    }
};
