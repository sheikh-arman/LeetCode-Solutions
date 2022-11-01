class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int>ans;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<m;i++){
            int posx=0,j=i,cal=-1;
            while(posx<n){
                if(grid[posx][j]==1){
                    if(j+1<m){
                        if(grid[posx][j+1]==1){
                            posx++;
                            j++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    if(j-1>=0){
                        if(grid[posx][j-1]==-1){
                            posx+=1;j-=1;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            if(posx==n){
                cal=j;
            }
            ans.push_back(cal);
        }
        return ans;
    }
};