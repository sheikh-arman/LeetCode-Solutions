class Solution {
public: vector<int>store;

     void dfs(TreeNode* node){ //dfs traversal
         if(node==NULL) return;
         store.push_back(node->val);
         dfs(node->left);       //left call
         dfs(node->right);      //right call
      } 


    int getMinimumDifference(TreeNode* root) {
        dfs(root);             //function calling
        sort(store.begin(),store.end());
        int result=INT_MAX;  
        for(int i=0;i+1<store.size();++i){  //finding two no such that their differnce is minimum
             if(store[i+1]-store[i]<result){
                result=store[i+1]-store[i];
             }
        }
        return result;;
    }
};