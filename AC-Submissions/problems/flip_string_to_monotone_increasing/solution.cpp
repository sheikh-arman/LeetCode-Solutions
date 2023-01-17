class Solution {
public:
    int ar0[100010];
    int ar1[100010];
    int minFlipsMonoIncr(string s) {
        s="0"+s;
        s+="1";
        int cnt=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')cnt++;
            ar0[i]=cnt;
        }
        cnt=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0')cnt++;
            ar1[i]=cnt;
        }
        int ans=10000000;
        for(int i=1;i<n-1;i++){
            int res1=ar0[i-1]+ar1[i+1];
            ans=min(ans,res1);
        }
        return ans;
    }
};