class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int ar[k+1];
        for(int i=0;i<k;i++){
            ar[i]=0;
        }
        int ans=0;
        ar[0]=1;
        int sum=0;
        for(int i:nums){
            sum+=i;
            if(sum<0){
                sum+=((abs(sum)/k)+1)*(k);
            }
            //cout<<i%k<<" ";
            ans+=ar[sum%k];
            ar[sum%k]++;
        }
        return ans;
    }
};