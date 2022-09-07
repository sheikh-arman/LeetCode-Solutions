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
    string s;
    void rec(TreeNode* root){
        if(root==NULL){
            return;
        }
        if(root->val<0){
            s+='-';
            root->val*=-1;
        }
        s+=to_string(root->val);
        if(root->left!=NULL){
            s+='(';
            rec(root->left);
            s+=')';
         }
        
        if(root->right!=NULL){
            if(root->left==NULL){
              s+='(';
              s+=')';
             }
            s+='(';
            rec(root->right);
            s+=')';
        }
    }
    string tree2str(TreeNode* root) {
        rec(root);
        return s;
    }
};