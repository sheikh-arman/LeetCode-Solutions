class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int>mp;
        int n=nums.size();
        vector<int>V;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int twice=0,mis=0;
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                mis=i;
            }
            if(mp[i]>1){
                twice=i;
            }
        }
        V.push_back(twice);
        V.push_back(mis);
        return V;
    }
};