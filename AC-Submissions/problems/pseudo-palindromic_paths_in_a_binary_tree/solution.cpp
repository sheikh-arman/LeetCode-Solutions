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
int ar[11],ans;
void sol(TreeNode* root){
    if(root==NULL){
        return;
    }
    ar[root->val]++;
    if(root->left==NULL&&root->right==NULL){
        int cnt=0;
        for(int i=0;i<10;i++){
            cnt+=ar[i]%2;
        }
        if(cnt<=1)ans++;
    }
    sol(root->left);
    sol(root->right);
    ar[root->val]--;
}
class Solution {
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        for(int i=0;i<10;i++){
            ar[i]=0;
        }
        ans=0;
        sol(root);
        return ans;
    }
};