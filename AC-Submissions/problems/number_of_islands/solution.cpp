class Solution {
public:
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dx[]= {1,-1,0,0,1,-1,-1,1};
        int dy[]= {0,0,1,-1,1,1,-1,-1};
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    while(!q.empty()){
                        int x=q.front().first;
                        int y=q.front().second;
                        q.pop();
                        grid[x][y]='0';
                        for(int k=0;k<4;k++){
                            int xx=x+dx[k];
                            int yy=y+dy[k];
                            if(xx>=0&&xx<n&&yy>=0&&yy<m&&grid[xx][yy]=='1'){
                                grid[xx][yy]='0';
                                q.push({xx,yy});
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};