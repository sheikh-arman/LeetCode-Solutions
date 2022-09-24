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
    vector<vector<int>>ans; //vector to store final ans
    void helper(TreeNode *root,vector<int>&temp,int target,int currsum){
        if(root==NULL) //if the current node is null ,simply return and do nothing
            return;     
        currsum+=root->val; // add the value of the curr node as we need to traverse the whole branch till leaf is encourntered
        
        temp.push_back(root->val); // including the node val in array as this can be a potential ans
        if(target==currsum && root->left==NULL && root->right==NULL){  //if we are at leaf node and our current sum is equal to targetsum then we have found 1 ans
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        helper(root->left,temp,target,currsum); //dfs on left subtree
        helper(root->right,temp,target,currsum); //dfs on right subtree

        temp.pop_back(); //since I am passing the temp arr by reference , hence need to remove the curr node once its left and right child are traversed
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        helper(root,temp,targetSum,0);
        return ans;
    }
};