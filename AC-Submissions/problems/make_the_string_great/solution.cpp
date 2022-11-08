class Solution {
public:
    string makeGood(string s) {
        if(s.length()==0 || s.length()==1)
            return s;
        string res;
        for(int i=0;i<s.length();i++){
            res.push_back(s[i]);
            while(res.size() && abs(res.back()-s[i+1])==32){  //the difference btw the lower and upper case alphabets is always 32 as per ascii
                res.pop_back();
                i++;
            }
        }
        return res;
    }
};