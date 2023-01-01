class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>V;
        string ss;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==' '){
                V.push_back(ss);
                ss.clear();
            }
            else{
                ss+=s[i];
            }
        } V.push_back(ss);
        n=pattern.size();
        map<char,string>mp;
        map<string,char>mp2;
        if(pattern.size()!=V.size())return 0;
        for(int i=0;i<n;i++){
            if(mp.count(pattern[i])||mp2.count(V[i])){
                if(mp[pattern[i]]!=V[i])return 0;
                if(mp2[V[i]]!=pattern[i])return 0;
            }
            else{
                mp[pattern[i]]=V[i];
                mp2[V[i]]=pattern[i];
            }
        }
        return 1;
    }
};