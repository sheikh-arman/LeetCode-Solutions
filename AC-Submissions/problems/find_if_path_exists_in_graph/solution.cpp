class Solution {
public:
    void dfs(int s,vector<bool> &vis,vector<int> g[])
    {
        vis[s]=true;
        for(auto child : g[s])
        {
            if(vis[child]) continue;
            dfs(child,vis,g);
        }
        return;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> g[n+5];
        for(auto val : edges)
        {
            g[val[0]].push_back(val[1]);
            g[val[1]].push_back(val[0]);
        }
        vector<bool> vis(n+5,false);
        dfs(source,vis,g);
        if(vis[destination]) return true;
        return false;
    }
};