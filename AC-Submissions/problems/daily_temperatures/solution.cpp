class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t){
        vector<int>ans;stack<pair<int,int>>s;
        ans.push_back(0);
        s.push({t[t.size()-1],t.size()-1});
        for(int i=t.size()-2;i>=0;i--)
        {
            while(!s.empty() and t[i]>=s.top().first)
            {
                s.pop();
            }
            if(!s.empty())
            ans.push_back(s.top().second-i);
            else
            ans.push_back(0);
            s.push({t[i],i});
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};