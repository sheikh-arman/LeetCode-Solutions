typedef long long int ll;
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<ll, null_type, less_equal<ll>, rb_tree_tag,tree_order_statistics_node_update> policy_set;

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ll ans=0;
        ll n=nums1.size();
        policy_set V;
        V.insert(nums1[n-1]-nums2[n-1]);
        ll cnt=1;
        for(int i=n-2;i>=0;i--){
            ll val=nums1[i]-nums2[i];
            ll pos=V.order_of_key(val-diff);
            ans+=(cnt-pos);
            cnt++;
            V.insert(val);
        }
        return ans;
    }
};