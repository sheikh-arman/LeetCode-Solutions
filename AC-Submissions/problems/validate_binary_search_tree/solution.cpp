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
typedef long long int ll;
class Solution {
public:
    bool rec(TreeNode* root,ll l,ll r){
        if(root==NULL){
            return 1;
        }
        bool ans=1;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        if(left!=NULL){
            ll tm_r=min(r,(ll)root->val);
            if(left->val>l&&left->val<tm_r){
                ans&=rec(left,l,tm_r);
            }
            else{
                ans=0;
            }
        }
        if(right!=NULL){
            ll tm_l=max(l,(ll)root->val);
            if(right->val>tm_l && right->val<r){
                ans&=rec(right,tm_l,r);
            }
            else{
                ans=0;
            }
        }
        return ans;
    }
    bool isValidBST(TreeNode* root) {
        bool ans=rec(root,LONG_LONG_MIN,LONG_LONG_MAX);
        return ans;
    }
};