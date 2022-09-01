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
    int ans;
    void sol(TreeNode*root , int mx){
        if(root==NULL){
            return;
        }
        if(root->val>=mx){
            mx=root->val;
            ans++;
        }
        sol(root->left,mx);
        sol(root->right,mx);
        
    }
    int goodNodes(TreeNode* root) {
        ans=0;
        sol(root,-100000000);
        return ans;
    }
};