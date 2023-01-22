class Solution {
public:
    vector<vector<string>>ans;
    int n;
    vector<string>V;
    int ck(string s1){
        string s2=s1;
        reverse(s2.begin(),s2.end());
        return (s1==s2);
    }
    string str;
    void sol(int pos){
        if(pos>=n){
            ans.push_back(V);
            return;
        }
        string s;
        for(int j=pos;j<n;j++){
            s+=str[j];
            if(ck(s)){
                V.push_back(s);
                sol(j+1);
                V.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        str=s;
        n=s.size();
        sol(0);
        return ans;
    }
};