class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ar[28]={0};
        int ar2[28]={0};
        for(int i=0;ransomNote[i]!='\0';i++){
            ar[ransomNote[i]-'a']++;
        }
        for(int i=0;magazine[i]!='\0';i++){
            ar2[magazine[i]-'a']++;;
        }
        for(int i=0;i<26;i++){
            //cout<<ar[i]<<" "<<ar2[i]<<" x\n";
            if(ar[i]>ar2[i])return false;
        }
        return true;
    }
};