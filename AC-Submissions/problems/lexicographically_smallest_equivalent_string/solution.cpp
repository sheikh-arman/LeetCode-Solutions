class Solution {
public:
    int rep[30];
    int Find(int node){
        return (node==rep[node]?node:rep[node]=Find(rep[node]));
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i=0;i<26;i++){
            rep[i]=i;
        }
        int n=s1.size();
        for(int i=0;i<n;i++){
            int a=Find(s1[i]-'a');
            int b=Find(s2[i]-'a');
            if(a>b)swap(a,b);
            rep[b]=a;
        }
        n=baseStr.size();
        for(int i=0;i<n;i++){
            baseStr[i]=(char)(Find(baseStr[i]-'a')+'a');
        }
        return baseStr;
    }
};