class Solution {
public:
    int mem[1010][2010];
    int dp(int i,int k,vector<vector<int>>& piles){
        int n=piles.size();
        if(k<=0||i>=n){
            return 0;
        }
        if(mem[i][k]!=-1){
            return mem[i][k];
        }
        int ans=0,sum=0;
        int j=piles[i].size();
        for(int x=0;x<min(j,k);x++){
            sum+=piles[i][x];
            ans=max(ans,sum+dp(i+1,k-(x+1),piles));
        }
        ans=max(ans,dp(i+1,k,piles));
        return mem[i][k]=ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=2000;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,k,piles);
        return ans;
    }
};