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
    void sol(TreeNode* root){
        if(root==nullptr)return;
        sol(root->left);
        sol(root->right);
        TreeNode* tm=root->left;
        root->left=root->right;
        root->right=tm;
    }
    TreeNode* invertTree(TreeNode* root) {
        sol(root);
        return root;
    }
};