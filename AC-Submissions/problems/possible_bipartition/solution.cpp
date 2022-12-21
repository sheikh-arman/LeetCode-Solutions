class Solution {
public:
    vector<int>edj[2010];
    int color[2010];
    int ans=1;
    bool dfs(int n){
        bool ans=1;
        for(int i:edj[n]){
            if(color[i]==-1){
                color[i]=1-color[n];
                ans&=dfs(i);
            }
            else if(color[i]!=1-color[n]){
                ans=0;
            }
        }
        return ans;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m=dislikes.size();
        for(int i=0;i<m;i++){
            int u,v;
            u=dislikes[i][0];
            v=dislikes[i][1];
            edj[u].push_back(v);
            edj[v].push_back(u);
        }
        for(int i=1;i<=n;i++){
            color[i]=-1;
        }
        bool ans=1;
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                color[i]=1;
                ans&=dfs(i);
            }
        }
        return ans;
    }
};