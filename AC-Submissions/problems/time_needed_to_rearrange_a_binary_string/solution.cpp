class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int ans=0;
        while(1){
            int ck=0;
            int n=s.size();
            for(int i=1;i<n;i++){
                if(s[i-1]=='0'&&s[i]=='1'){
                    s[i-1]='1';
                    s[i]='0';
                    i+=1;
                    ck=1;
                }
            }
            if(ck==0)break;
            ans++;
        }
        return ans;
    }
};