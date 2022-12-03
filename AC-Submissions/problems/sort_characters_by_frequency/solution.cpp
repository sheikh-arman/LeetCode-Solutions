class Solution {
public:
    string frequencySort(string s) {
        int ar[260];
        for(int i=0;i<250;i++)ar[i]=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            ar[s[i]-'0']++;
        }
        vector<pair<int,int>>V;
        for(int i=0;i<250;i++){
            if(ar[i])
            V.push_back({ar[i],i});
        }
        sort(V.begin(),V.end(),greater<pair<int,int>>());
        s.clear();
        for(auto i:V){
            while(i.first--){
                s+=(char)(i.second + '0');
            }
        }
        return s;
    }
};