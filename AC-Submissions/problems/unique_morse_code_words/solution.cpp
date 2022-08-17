class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string s[27]={".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        map<string,int>mp;
        int n=words.size(),ans=0;
        for(int i=0;i<n;i++){
            string s2=words[i];
            string t;
            for(int j=0;s2[j]!='\0';j++){
               t+=s[s2[j]-'a'];
            }
            if(!mp.count(t)){
                ans++;
                mp[t]=1;
            }
        }
        return ans;
    }
    
};