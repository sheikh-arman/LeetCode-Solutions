class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        int q=queries.size();
        vector<int>ans;
        for(int i=0;i<q;i++){
            int pos=upper_bound(nums.begin(),nums.end(),queries[i])-nums.begin();
            ans.push_back(pos);
        }
        return ans;
    }
};