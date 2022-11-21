class Solution {
public:
    int dx[10]={1,-1,0,0};
    int dy[10]={0,0,1,-1};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n,m;
        n=maze.size();
        m=maze[0].size();
        int ans=10000000;
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        
        int ar[110][110];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                ar[i][j]=-1;
            }
        }
        ar[entrance[0]][entrance[1]]=0;
        while(!q.empty()){
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int cx=x+dx[i];
                int cy=y+dy[i];
                if(cx>=0&&cx<n&&cy>=0&&cy<m){
                    if(ar[cx][cy]==-1&&maze[cx][cy]=='.'){
                        ar[cx][cy]=ar[x][y]+1;
                        if(cx==0||cx==n-1||cy==0||cy==m-1){
                            ans=min(ans,ar[cx][cy]);
                        }
                        q.push({cx,cy});
                    }
                }
            }
        }
        if(ans>=1000000)ans=-1;
        return ans;
    }
};