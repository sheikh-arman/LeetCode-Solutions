class Solution {
public:
    int dfs(vector<int>& edges, int curr, int c, vector<int>& vis, vector<int>& dp){
        if(curr==-1) return -1;
        if(dp[curr]) return dp[curr];
        if(vis[curr]) { dp[curr]=c-vis[curr]+1; return dp[curr]; }
        c++;
        vis[curr]=c;
        int k=dfs(edges, edges[curr], c, vis, dp);
        dp[curr]=k;
        return k;
    } 
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> dp(n);
        int ans=-1;
        vector<int> vis(n);
        for(int i=0;i<n;i++){
            ans=max(ans, dfs(edges, i, 0, vis, dp));
        }
        return ans;
    }
};