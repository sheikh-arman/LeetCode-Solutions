class Solution {
public:
    int mem[1010][1010];
    int dp(int i,int j,string &s){
        if(i>=j){
            return i==j;
        }
        if(mem[i][j]!=-1){
            return mem[i][j];
        }
        int ans=0;
        if(s[i]==s[j]){
            ans=dp(i+1,j-1,s)+2;
        }
        else{
            ans=max(dp(i+1,j,s),dp(i,j-1,s));
        }
        return mem[i][j]=ans;
    }
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mem[i][j]=-1;
            }
        }
        int ans=dp(0,n-1,s);
        return ans;
    }
};