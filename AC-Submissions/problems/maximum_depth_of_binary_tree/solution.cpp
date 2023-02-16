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
    int sol(TreeNode* root){
        if(root==nullptr){
            return 0;
        }
        int ans=max(sol(root->left),sol(root->right))+1;
        return ans;
    }
    int maxDepth(TreeNode* root) {
        int ans=sol(root);
        return ans;
    }
};