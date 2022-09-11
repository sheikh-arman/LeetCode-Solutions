class Solution {
public:
    typedef long long int ll;
    ll mod=1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<ll, vector<ll>, greater<ll> >pq;
        vector<pair<int,int>>V;
        for(int i=0;i<n;i++){
            V.push_back({efficiency[i],speed[i]});
        }
        sort(V.begin(),V.end());
        reverse(V.begin(),V.end());
        ll sum=0,ans=0;
        for(int i=0;i<k;i++){
            sum+=V[i].second;
            pq.push(V[i].second);
            ans=max(ans,sum*V[i].first);
        }
        for(int i=k;i<n;i++){
            sum-=pq.top();
            pq.pop();
            sum+=V[i].second;
            pq.push(V[i].second);
            ans=max(ans,sum*V[i].first);
        }
        ans%=mod;
        return (int)ans;
    }
};