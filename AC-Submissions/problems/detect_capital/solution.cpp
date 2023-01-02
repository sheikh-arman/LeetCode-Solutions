class Solution {
public:
    bool detectCapitalUse(string word) {
        int n=word.size();
        if(word[n-1]>='A'&&word[n-1]<='Z'){
            for(int i=0;i<n;i++){
                if(word[i]>='A'&&word[i]<='Z'){
                    
                }
                else{
                    return 0;
                }
            }
            return 1;
        }
        else{
            for(int i=1;i<n;i++){
                if(word[i]>='A'&&word[i]<='Z'){
                    return 0;
                }
            }
            return 1;
        }
        return 1;
    }
};