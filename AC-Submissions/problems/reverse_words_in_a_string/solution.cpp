class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string ans;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                if((int)ans.size()>0)
                v.push_back(ans);
                ans.clear();
            }
            else{
                ans+=s[i];
            }
        }
        if((int)ans.size()>0)
        v.push_back(ans);
        reverse(v.begin(),v.end());
        string sol;
        int ck=1;
        for(auto i:v){
            if(ck==0)sol+=' ';
            sol+=i;
            ck=0;
        }
        return sol;
    }
};