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
    TreeNode* help(vector<int>& inorder, int n,int m,vector<int>& postorder,int a,int b)
    {
        if(a>b || n>m)
        {
            return NULL;
        }
        TreeNode* curRoot = new TreeNode(postorder[b]);
        int i=n;
        while(inorder[i]!=postorder[b])
        {
            i++;
        }
        curRoot->left = help(inorder,n,i-1,postorder,a,a+i-n-1);
        curRoot->right = help(inorder,i+1,m,postorder,a+i-n,b-1);
        return curRoot;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return help(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
};