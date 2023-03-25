class Solution {
public:
    int dfs(vector<vector<int>>& adj, vector<bool>& vis, int src){
        int cnt = 1;
        vis[src] = true;
        for(auto u : adj[src]){
            if(!vis[u]){
                cnt += dfs(adj, vis, u);
            }
        }
        return cnt;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        
        vector<bool> vis(n);
        vector<int> sizes;
        for(int i=0; i<n;i++){
            if(!vis[i]){
                sizes.push_back(dfs(adj,vis,i));
            }
        }
        
        long long res=0;
        int temp=0;
        for(int i=0;i<sizes.size();i++){
            res += (long long)sizes[i] * (n-temp-sizes[i]);
            temp+=sizes[i];
        }
        
        return res;
    }
};