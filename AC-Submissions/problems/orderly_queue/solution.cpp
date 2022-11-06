class Solution {
public:
    string orderlyQueue(string s, int k) {
         string str=s;
        if(k>1){
            sort(str.begin(),str.end());
        }
        else{
            int n=s.size();
            for(int i=0;i<n;i++){
                s+=s[0];
                s.erase(s.begin());
                if(str>s){
                    str=s;
                }
            }
        }
        return str;
    }
};