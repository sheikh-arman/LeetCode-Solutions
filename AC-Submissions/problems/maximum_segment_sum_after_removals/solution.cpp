typedef long long int ll;
class Solution {
public:
    ll rep[100010];
    ll sum[100010];
    ll Find(ll node){
        return (rep[node]==node?node:rep[node]=Find(rep[node]));
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        ll n=nums.size();
        ll ans=0;
        ll ar[n+10];
        vector<long long>V;
        for(ll i=0;i<=n+1;i++){
            ar[i]=0;
            rep[i]=i;
            sum[i]=0;
        }
        for(int i=n-1;i>=0;i--){
            V.push_back(ans);
            ll val=removeQueries[i];
            ar[val]=1;
            sum[val]=nums[val];
            ll new_sum=nums[val];
            if(ar[val+1]==1){
                ll u=Find(val+1);
                ll v=Find(val);
                new_sum=sum[u]+sum[v];
                rep[u]=v;
                sum[v]=new_sum;
                sum[u]=0;
            }
            if(val>0&&ar[val-1]==1){
                ll u=Find(val-1);
                ll v=Find(val);
                new_sum=sum[u]+sum[v];
                rep[u]=v;
                sum[v]=new_sum;
                sum[u]=0;
            }
            ans=max(ans,new_sum);
        }
        reverse(V.begin(),V.end());
        return V;
        
    }
};