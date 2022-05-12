class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>V;
        sort(nums.begin(),nums.end());
        do{
            vector<int>tm;
            for(int i:nums){
                tm.push_back(i);
            }
            V.push_back(tm);
        }
        while(next_permutation(nums.begin(),nums.end()));
        return V;
    }
};