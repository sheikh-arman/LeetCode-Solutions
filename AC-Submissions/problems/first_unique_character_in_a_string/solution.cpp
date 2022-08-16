class Solution {
public:
    int firstUniqChar(string s) {
        int ar[27];
        for(int i=0;i<26;i++)ar[i]=0;
        for(int i=0;s[i]!='\0';i++){
            int val=s[i]-'a';
            ar[val]++;
        }
        for(int i=0;s[i]!='\0';i++){
            if(ar[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};