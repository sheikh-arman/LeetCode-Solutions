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
    bool dp(TreeNode* root){
        if(root==NULL){
            return 0;
        }
        bool ans=(root->val==1);
        bool ans2=dp(root->left);
        bool ans3=dp(root->right);
        if(ans2==0){
            root->left=NULL;
        }
        if(ans3==0){
            root->right=NULL;
        }
        ans|=ans2;
        ans|=ans3;
        if(ans==0){
            root=NULL;
        }
        return ans;
    }
    TreeNode* pruneTree(TreeNode* root) {
        bool tut=dp(root);
        if(root->val==0&&root->left==NULL&&root->right==NULL){
            root=NULL;
        }
        return root;
    }
};