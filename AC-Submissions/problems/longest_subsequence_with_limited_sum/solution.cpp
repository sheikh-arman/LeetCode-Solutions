class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int>V;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
        }
        for(int i:queries){
            int pos=upper_bound(nums.begin(),nums.end(),i)-nums.begin();
            V.push_back(pos);
        }
        return V;
    }
};