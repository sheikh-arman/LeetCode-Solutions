class Solution {
public:
    string oddString(vector<string>& words) {
        int n=words.size();
        string s;
        map<vector<int>,int>mp;
        for(int i=0;i<n;i++){
            string str=words[i];
            vector<int>st;
            for(int j=1;str[j]!='\0';j++){
                st.push_back(str[j]-str[j-1]);
            }
            if(mp.count(st)){
                mp[st]++;
            }
            else{
                mp[st]=1;
            }
        }
        for(int i=0;i<n;i++){
            string str=words[i];
            vector<int>st;
            for(int j=1;str[j]!='\0';j++){
                st.push_back(str[j]-str[j-1]);
            }
            if(mp[st]==1){
                s=str;
            }
        }
        return s;
    }
};