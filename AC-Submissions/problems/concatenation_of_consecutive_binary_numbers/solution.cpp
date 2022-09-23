class Solution {
public:
    int concatenatedBinary(int n) {
        long long int ans=0,pow=1;
        int mod=1e9+7;
        for(int i=n;i>=1;i--){
            int num=i;
            while(num){
                if(num&1){
                    ans=pow+ans;
                }
                num>>=1;
                if(ans>=mod)ans%=mod;
                pow<<=1;
                if(pow>=mod)pow%=mod;
            }
        }
        return ans;
    }
};