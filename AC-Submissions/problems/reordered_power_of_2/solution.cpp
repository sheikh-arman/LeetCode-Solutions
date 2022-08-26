class Solution {
public:
    string st(int n){
        string s;
        while(n){
            s+=(n%10)-'0';
            n/=10;
        }
        sort(s.begin(),s.end());
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string s=st(n);
        int cnt=1;
        while(1){
            string s2=st(cnt);
            if(s==s2){
                return 1;
            }
            cnt*=2;
            if(cnt>1000000000)break;
        }
        return 0;
    }
};