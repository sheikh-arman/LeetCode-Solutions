class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])==0){
                mp[nums[i]]=i;
            }
            else{
                if(i-mp[nums[i]]<=k){
                    return 1;
                }
                mp[nums[i]]=i;
            }
        }
        return 0;
    }
};