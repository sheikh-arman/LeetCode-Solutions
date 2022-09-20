class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans=0;
        for(int i=0;i<nums1.size();i++)
        {
            int cnt=0;
            for(int j=0,k=i;j<nums2.size()&&k<nums1.size();j++,k++)
            {
                if(nums1[k]==nums2[j]){
                    cnt++;
                    continue;
                }
                ans=max(ans,cnt);
                cnt=0;
            }
            
            ans=max(ans,cnt);
        }
        for(int i=0;i<nums2.size();i++)
        {
            int cnt=0;
            for(int j=0,k=i;j<nums1.size()&&k<nums2.size();j++,k++)
            {
                if(nums2[k]==nums1[j]){
                    cnt++;
                    continue;
                }
                ans=max(ans,cnt);
                cnt=0;
            }
            ans=max(ans,cnt);
        }
        return ans;
    }
};