typedef long long int ll;
class Solution {
public:
    ll mem[32][1010],kk;
    ll mod=1e9+7;
    ll dp(ll cnt,ll target){
        if(target==0)return cnt==0;
        if(target<0)return 0;
        if(mem[cnt][target]!=-1){
            return mem[cnt][target];
        }
        ll ans=0;
        if(cnt>0){
            for(int i=1;i<=kk;i++){
                ans+=dp(cnt-1,target-i);
                ans%=mod;
            }
        }
        return mem[cnt][target]=ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        kk = k;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=target;j++){
                mem[i][j]=-1;
            }
        }
        ll ans=dp(n,target);
        return (int)ans;
    }
};