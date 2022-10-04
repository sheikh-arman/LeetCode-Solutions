class Solution {
    bool hasPath(TreeNode *node, int targetSum) {
        if(!node)
            return false;
        if(!node->left && !node->right) {
            return node->val == targetSum;
        }
        return hasPath(node->left, targetSum - node->val) || hasPath(node->right, targetSum - node->val);  
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return hasPath(root, targetSum);
    }
};