class Solution {
public:
    bool halvesAreAlike(string s) {
        int cnt1=0,cnt2=0;
        map<char,int>mp;
        mp['a']=1;mp['A']=1;
        mp['e']=1;mp['E']=1;
        mp['i']=1;mp['I']=1;
        mp['o']=1;mp['O']=1;
        mp['u']=1;mp['U']=1;
        int n=s.size();
        for(int i=0;i<n/2;i++){
            cnt1+=mp[s[i]];
        }
        for(int i=n/2;i<n;i++){
            cnt2+=mp[s[i]];
        }
        return (cnt1==cnt2);
    }
};