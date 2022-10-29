typedef long long int ll;
#define N 100010
class Solution {
public:
    ll seg_tree[4*N];
    ll ar[N+10];
    ll build(ll n,ll b,ll e)
    {
    if(b==e)
    {
        seg_tree[n]=ar[b];
        return seg_tree[n];
    }
    ll p=build(n*2,b,(b+e)/2);
    ll q=build(n*2+1,(b+e)/2+1,e);
    return seg_tree[n]=max(p,q);
    }
    ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>=i&&e<=j)
    {
        return seg_tree[n];
    }
    if(e<i||b>j)
    {
        return -1;
    }
    ll p=query(n*2,b,(b+e)/2,i,j);
    ll q=query(n*2+1,(b+e)/2+1,e,i,j);
    return max(p,q);

}
    ll bin_s(ll left,ll right,ll val){
        ll fst=left;
        ll n=right;
        ll ans=-1;
        while(left<=right){
            ll mid=(left+right)/2;
            ll tm=query(1,1,n,fst,mid);
            if(tm>val){
                ans=mid;
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        return ans;
    }
    vector<int> secondGreaterElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            ar[i+1]=nums[i];
        }
        ll x=build(1,1,n);
        vector<int>V;
        for(int i=1;i<=n;i++){
            ll x=bin_s(i+1,n,ar[i]);
            if(x!=-1){
                x=bin_s(x+1,n,ar[i]);
            }
            if(x!=-1)x=ar[x];
            V.push_back((int)x);
        }
        return V;
    }
};