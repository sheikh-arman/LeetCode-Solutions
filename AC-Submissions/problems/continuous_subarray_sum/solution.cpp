class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(k==1&&nums.size()>1)return 1;
        map<int,int>mp;
        int siz=nums.size(),sum=0,ck=0;
        for(int i=0;i<siz;i++){
            sum+=nums[i];
            sum%=k;
            mp[sum]=i;
            if(sum==0&&nums[i]%k!=0)ck=1;
            nums[i]=sum;
        }
        for(int i=0;i<siz-1;i++){
            if(abs(mp[nums[i]]-i)>1){
                ck=1;
            }
        }
        return ck;
    }
};