class Solution {
public:
    typedef long long int ll;
    int minimumAverageDifference(vector<int>& nums) {
        ll mi=999999999;
        ll sum=0;
        for(int i:nums){
            sum+=i;
        }
        ll s=0,cnt=1,n=nums.size()-1,ind;
        for(ll i:nums){
            s+=i;
            ll tm;
            if(n==0){
                tm=s/cnt;
                if(tm<mi){
                    ind=cnt-1;
                }
                break;
            }
            tm=abs((s/cnt)-(sum-s)/n);
            if(tm<mi){
                mi=tm;
                ind=cnt-1;
            }
            cnt++;
            n--;
        }
        return (int)ind;
    }
};