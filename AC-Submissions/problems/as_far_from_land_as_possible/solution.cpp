class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={-1,1,0,0};
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int,int>>q;
        int label[n+1][n+1];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                label[i][j]=-1;
                if(grid[i][j]==1){
                    q.push({i,j});
                    label[i][j]=0;
                }
            }
        }
        int ans=-1;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int cx=x+dx[i];
                int cy=y+dy[i];
                if(cx>=0&&cx<n&&cy>=0&&cy<n&&label[cx][cy]==-1){
                    label[cx][cy]=label[x][y]+1;
                    ans=max(ans,label[cx][cy]);
                    q.push({cx,cy});
                }
            }
        }
        return ans;
    }
};