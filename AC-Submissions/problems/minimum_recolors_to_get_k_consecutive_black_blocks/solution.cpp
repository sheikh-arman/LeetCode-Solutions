class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        int left=0,right=0;
        int curr=0,ans=1000000000;
        while(right<k){
            if(blocks[right]=='W'){
                curr++;
            }
            right++;
        }
        ans=min(ans,curr);
        while(right<n){
            if(blocks[right]=='W'){
                curr++;
            }
            if(blocks[left]=='W')curr--;
            left++;
            right++;
            ans=min(ans,curr);
        }
        return ans;
    }
};