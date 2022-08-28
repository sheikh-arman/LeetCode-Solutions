class Solution {
public:
    string removeStars(string s) {
        int cnt=0;
        string rev;
        int n=s.size();
        for(int i=n-1;i>=0;i--){
            if(s[i]=='*'){
                cnt++;
            }
            else{
                if(cnt==0){
                    rev+=s[i];
                }
                else{
                    cnt--;
                }
            }
        }
        reverse(rev.begin(),rev.end());
        return rev;
    }
};