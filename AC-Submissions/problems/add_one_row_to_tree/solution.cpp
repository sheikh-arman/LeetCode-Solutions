class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        
        if(depth == 1)
        {
            TreeNode* newroot = new TreeNode(val);
            newroot->left = root;
            return newroot;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int sz = q.size();
            depth--;
            while(sz--)
            {
                TreeNode* t = q.front();
                q.pop();
                if(depth == 1)
                {
                    TreeNode* l = new TreeNode(val);
                    TreeNode* r = new TreeNode(val);
                    
                    l->left = t->left;
                    r->right = t->right;
                    
                    t->left = l;
                    t->right = r;
                }
                
                if(t->left) q.push(t->left);
                if(t->right) q.push(t->right);
            }
        }
        return root;
    }
};