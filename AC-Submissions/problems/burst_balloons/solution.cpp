class Solution {
public:
    int mem[310][310];
    int ar[310];
    int dp(int l,int r){
        if(l>r)return 0;
        if(mem[l][r]!=-1){
            return mem[l][r];
        }
        int ans=0;
        for(int i=l;i<=r;i++){
            ans=max(ans,dp(l,i-1)+dp(i+1,r)+ar[l-1]*ar[i]*ar[r+1]);
        }
        return mem[l][r]=ans;
    }
    int maxCoins(vector<int>& nums) {
        ar[0]=1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ar[i+1]=nums[i];
        }
        ar[n+1]=1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(1,n);
        return ans;
    }
};