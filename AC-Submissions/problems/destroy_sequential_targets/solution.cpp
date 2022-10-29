class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int>mp;
        int tm,ma=0;
        for(int i:nums){
            int val=i%space;
            mp[val]++;
            if(ma<mp[val]){
                ma=mp[val];
            }
        }
        int ans;
        ans=1200000000;
        for(int i:nums){
            int val=i%space;
            if(mp[val]==ma){
                ans=min(ans,i);
            }
        }
        return ans;
    }
};