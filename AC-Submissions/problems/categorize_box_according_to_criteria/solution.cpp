class Solution {
public:
    string categorizeBox(int length, int width, int height, int mass) {
        int ck=0;
        if(mass>=100){
            ck+=1;
        }
        long long int x=(long long int)length*(long long int)width*(long long int)height;
        if(length>=10000||width>=10000||height>=10000||x>=1000000000){
            ck+=10;
        }
        string s;
        if(ck==11){
            s="Both";
        }
        else if(ck==0){
            s="Neither";
        }
        else if(ck==1){
            s="Heavy";
        }
        else if(ck==10){
            s="Bulky";
        }
        return s;
    }
};