class Solution {
private:
    void dfs(int row,int col, vector<vector<int>>&vis,vector<vector<int>>&grid,int count,int &block,int &res)
    {
        int n=grid.size();
        int m=grid[0].size();

        vis[row][col]=1;
        count++;
        
        // cout<<count<<":"<<block<<": "<<row<<"-"<<col<<endl;
        if(count==block and grid[row][col]==2)
        {
            res++;
        }

        int dlr[4]={-1,0,1,0};
        int clr[4]={0,1,0,-1};

        for(int i=0;i<4;i++)
        {
            int nr=row+dlr[i];
            int nc=col+clr[i];

            if(nr>=0 and nr<n and nc>=0 and nc<m 
                and vis[nr][nc]==-1 and grid[nr][nc]!=-1 )
            {
                dfs(nr,nc,vis,grid,count,block,res);
            }
        }

        count--;
        vis[row][col]=-1;
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        
    int n=grid.size();
    int m=grid[0].size();

    vector<vector<int>>vis(n,vector<int>(m,-1));
    int a,b,c,d;
    int block=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==1)
            {
                a=i;
                b=j;
                cout<<a<<"   "<<b<<endl;
            }
            else if(grid[i][j]==-1)
            {
                block++;
                vis[i][j]=1;
            }
            // else if(grid[i][j]==2)
            //     cout<<"2 is at : "<<i<<" "<<j<<endl;

        }
    }
    block=(n*m)-block;
    int res=0,count=0;

    dfs(a,b,vis,grid,count,block,res);

    return res;
}
};