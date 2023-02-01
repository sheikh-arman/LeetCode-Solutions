class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int ans=0;
        int n=str1.size();
        int m=str2.size();
        for(int i=min(n,m);i>=1;i--){
            int ck=1;
            string s=str1.substr(0,i);
            if(n%i||m%i)continue;
            for(int j=0;j<n;j+=i){
                string s2=str1.substr(j,i);
                if(s2!=s){
                    ck=0;break;
                }
            }
            for(int j=0;j<m;j+=i){
                string s2=str2.substr(j,i);
                if(s2!=s){
                    ck=0;break;
                }
            }
            if(ck){
                ans=i;break;
            }
        }
        string s=str1.substr(0,ans);
        return s;
    }
};