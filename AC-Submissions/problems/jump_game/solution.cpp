class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int cnt=-1;
        int last=n-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]){
                if(last-i<=nums[i])
                    {
                    last=i;
                    }

                }

         }
        return last==0;
    }
};