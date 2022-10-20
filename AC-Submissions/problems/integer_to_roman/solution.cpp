class Solution {
public:
    string solution(int p,int cnt) {
            string ans="";
            if(cnt ==1){
                if(p==0) ans="";
                else if(p==1) ans ="I";
                else if(p==2) ans ="II";
                else if(p==3) ans ="III";
                else if(p==4) ans ="IV";
                else if(p==5) ans ="V";
                else if(p==6) ans ="VI";
                else if(p==7) ans ="VII";
                else if(p==8) ans ="VIII";
                else if(p==9) ans ="IX";
            } else if(cnt==2){
                if(p==0) ans="";
                else if(p==1) ans ="X";
                else if(p==2) ans ="XX";
                else if(p==3) ans ="XXX";
                else if(p==4) ans ="XL";
                else if(p==5) ans ="L";
                else if(p==6) ans ="LX";
                else if(p==7) ans ="LXX";
                else if(p==8) ans ="LXXX";
                else if(p==9) ans ="XC";
            } else if( cnt == 3){
                if(p==0) ans="";
                else if(p==1) ans ="C";
                else if(p==2) ans ="CC";
                else if(p==3) ans ="CCC";
                else if(p==4) ans ="CD";
                else if(p==5) ans ="D";
                else if(p==6) ans ="DC";
                else if(p==7) ans ="DCC";
                else if(p==8) ans ="DCCC";
                else if(p==9) ans ="CM";
            } else{
                if(p==0) ans="";
                else if(p==1) ans ="M";
                else if(p==2) ans ="MM";
                else if(p==3) ans ="MMM";
            }
            return ans;
        }
    string intToRoman(int num) {
        string ans="";
        int cn=1;
        while(num > 0) {
            int p = num%10;
            ans=solution(p,cn)+ans;
            cn+=1;
            num=num/10;
        }
        return ans;
    }
};