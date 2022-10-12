class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int ans=0;
        for(int i=n;i>=3;i--){
            if(nums[i-3]+nums[i-2]>nums[i-1]){
                ans=nums[i-3]+nums[i-2]+nums[i-1];break;
            }
        }
        return ans;
    }
};