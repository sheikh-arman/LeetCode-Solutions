class Solution {
public:
    int n,m;
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    void bfs(int stx,int sty,vector<vector<int>>& h,vector<vector<int>>& vis){
        queue<pair<int,int>> pq;
        pq.push({stx,sty});
        vis[stx][sty]=1;
        while(!pq.empty()){
            auto [x,y]=pq.front();pq.pop();
            for(int i=0;i<4;i++){
                int nx=x+dx[i],ny=y+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m && !vis[nx][ny] &&h[nx][ny]>=h[x][y]) {//if water can come from (nx,ny) to (x,y)
                    vis[nx][ny]=1;
                    pq.push({nx,ny});
                }
            }
        }
        
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        n=h.size(),m=h[0].size();
        vector<vector<int>> at(n,vector<int>(m,0));
        vector<vector<int>> pa(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++) bfs(i,0,h,pa); // left boundary for pacific 
        for(int j=0;j<m;j++) bfs(0,j,h,pa); // top boundary for pacific
        for(int i=0;i<n;i++) bfs(i,m-1,h,at); //right boundary for atlantic
        for(int j=0;j<m;j++) bfs(n-1,j,h,at); //bottom boundary for atlantic
        
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(at[i][j]==1 && pa[i][j]==1)ans.push_back({i,j}); //if water can go to both atlantic and pacific 
            }
        }
        return ans;
    }
};