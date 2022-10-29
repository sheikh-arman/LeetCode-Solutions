class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<pair<int,int>> v(n);
        for(int i=0 ; i<n ;i++){
            v.push_back({growTime[i], i});
        }
        
        sort(v.begin(), v.end());
        reverse(v.begin() , v.end());
        
        int maxx = 0;
        
        int ct = 0;
        
        
        for(int i=0 ; i<n ; i++){
            int idx = v[i].second;
            ct += plantTime[idx];
            maxx = max(maxx , ct+growTime[idx]);
        }
        
        
        return maxx;
    }
};