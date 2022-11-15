class Solution {
public:
    
    int countNodes(TreeNode* root) {
        
        // base case
        
        if(root == NULL)
            return 0;
        
        // find left height and right height for root
        
        int left_height = 0;
        
        int right_height = 0;
        
        TreeNode* left_pointer = root;
        
        TreeNode* right_pointer = root;
        
        // cal. left height
        
        while(left_pointer)
        {
            left_height++;
            
            left_pointer = left_pointer -> left;
        }
        
        // cal. right height
        
        while(right_pointer)
        {
            right_height++;
            
            right_pointer = right_pointer -> right;
        }
        
        // if left_height == right_height, then no. of nodes in subtree will be pow(2, h) - 1
        
        if(left_height == right_height)
            return pow(2, left_height) - 1;
        
        // if left_height != right_height then calculate no. of nodes for both the left subtree and right subtree
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};