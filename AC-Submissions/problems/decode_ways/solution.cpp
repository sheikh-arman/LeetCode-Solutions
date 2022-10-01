class Solution {
public:
    int mem[101];
    int dp(int pos, string &str){
        int n=str.size();
        if(pos>=n){
            return 1;
        }
        if(str[pos]=='0')return 0;
        if(mem[pos]!=-1){
            return mem[pos]; 
        }
        int ans=0;
        ans+=dp(pos+1,str);
        int val=str[pos]-'0';
        if(pos+1<n){
            val*=10;
            val+=(str[pos+1]-'0');
            if(val<=26){
                ans+=dp(pos+2,str);
            }
        }
        return mem[pos]=ans;
    }
    int numDecodings(string s) {
        for(int i=0;i<=100;i++)mem[i]=-1;
        int ans=dp(0,s);
        return ans;
    }
};