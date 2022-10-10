class Solution {
public:
    string breakPalindrome(string palindrome) {
       if(palindrome.size()==1){
           return "";
       }   
       int ck=0;
       int siz=palindrome.size();
        for(int i=0;i<siz/2;i++){
            if(palindrome[i]!='a'){
                ck=1;palindrome[i]='a';break;
            }
        }
        if(ck==0){
            palindrome[siz-1]='b';
        }
        return palindrome; 
    }
};