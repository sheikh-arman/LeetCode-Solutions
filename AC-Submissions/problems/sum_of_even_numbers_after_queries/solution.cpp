class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int N = nums.size() , M = queries.size();
        vector<int>ans(M);
        int cur = 0 ;
        for(int i = 0 ; i < N ;i++){
            if(nums[i]%2 == 0){
                cur += nums[i];
            }
        }
        for(int i = 0 ; i < M ;i++){
            int idx = queries[i][1] , val = queries[i][0];
            if(nums[idx]%2 == 0) cur -= nums[idx];
            nums[idx] += val;
            if(nums[idx]%2 == 0) cur += nums[idx];
            ans[i] = cur;
        }
        return ans;
        
    }
};