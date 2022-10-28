class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector< pair<string,string> >tot;
        vector<vector<string>>V;
        int n=strs.size();
        for(int i=0;i<n;i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            tot.push_back({s,strs[i]});
        }
        sort(tot.begin(),tot.end());
        for(int i=0;i<n;i++){
            vector<string>tm;
            tm.push_back(tot[i].second);
            int j=i+1;
            while(j<n){
                if(tot[j].first==tot[i].first){
                    tm.push_back(tot[j].second);j++;
                }
                else{
                    break;
                }
            }
            i=j-1;
            V.push_back(tm);
        }
        return V;
    }
};