class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int ar[30];
        for(int i=0;i<26;i++){
            ar[i]=0;
        }
        int cnt=0;
        for(int i=0;i<order[i]!='\0';i++){
            ar[order[i]-'a']=cnt++;
        }
        int n=words.size();
        for(int i=0;i<n-1;i++){
            string s=words[i];
            string s2=words[i+1];
            int m=s.size();
            int m2=s2.size(),ck=0;
            int mi=min(m,m2);
            for(int j=0;j<mi;j++){
                if(ar[s[j]-'a']<ar[s2[j]-'a']){
                    ck=1;
                    break;
                }
                if(ar[s[j]-'a']>ar[s2[j]-'a']){
                    return 0;
                }
            }
            if(!ck){
                if(m2<m)return 0;
            }
        }
        return 1;
    }
};