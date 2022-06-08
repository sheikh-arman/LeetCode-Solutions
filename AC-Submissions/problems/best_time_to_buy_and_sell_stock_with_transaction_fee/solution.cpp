class Solution {
public:
    int mem[50010][4],n,fe;
    vector<int>V;
    int dp(int i, int status){
        if(i>=n){
            return 0;
        }
        if(mem[i][status]!=-1){
            return mem[i][status];
        }
        int ans=INT_MIN;
        if(status){
               ans=dp(i+1,0)+V[i];
        }
        else{
            ans=dp(i+1,1)-(V[i]+fe);
        }
        ans=max(ans,dp(i+1,status));
        return mem[i][status]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        V=prices;
        n=V.size();
        fe=fee;
        for(int i=0;i<=n;i++){
             for(int k=0;k<2;k++){
                mem[i][k]=-1;
              }
        }
        int ans=dp(0,0);
        return ans;
    }
};