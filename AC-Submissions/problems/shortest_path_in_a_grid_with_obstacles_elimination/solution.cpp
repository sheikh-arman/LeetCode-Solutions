class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, -1)); 
        // Declared a vector of size m with n individual vector arrays with all -1 elements
        // visted = [vector1,vector1, ..... m-1]
        // vector1 = [-1,-1, ....... n-1]
        queue <vector<int>> myQ;
        myQ.push({0,0,0,k});
        // myQ({x, y, current Length, remaining k});
        while(!myQ.empty()){
            auto t = myQ.front();
            myQ.pop();
            int x = t[0], y = t[1];
            
            if(x<0 || x>=m || y<0 || y>=n) // going out of the grid
                continue;
            
            if(x==m-1 && y==n-1) // reached the end
                return t[2];
            
            if(grid[x][y]==1) // hitting an obstacle
            {
                if(t[3]>0) // check if we can remove that obstacle
                    t[3]--;
                else
                    continue;
            }
            
            if(visited[x][y]!=-1 && visited[x][y]>=t[3]) // means we have already visited this 
            { 
                continue;
            }
            
            visited[x][y] = t[3]; // remaining k's
            
            myQ.push({x+1,y,t[2]+1,t[3]});
            myQ.push({x-1,y,t[2]+1,t[3]});
            myQ.push({x,y+1,t[2]+1,t[3]});
            myQ.push({x,y-1,t[2]+1,t[3]});
            
        }
        return -1;
    }
};