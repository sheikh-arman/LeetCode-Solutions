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
    typedef long long int ll;
    ll label[100010];
    ll cnt[1000010];
    int ma;
    void sol(TreeNode* root,int lbl){
        if(root==NULL){
            return;
        }
        ma=max(ma,lbl);
        label[lbl]+=root->val;
        cnt[lbl]+=1;
        sol(root->left,lbl+1);
        sol(root->right,lbl+1);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        for(int i=0;i<=100000;i++){
            label[i]=0;
            cnt[i]=0;
        }
        ma=0;
        sol(root,0);
        vector<double>V;
        for(int i=0;i<=ma;i++){
            double x=(double)label[i]/(double)cnt[i];
            V.push_back(x);
        }
        return V;
    }
};