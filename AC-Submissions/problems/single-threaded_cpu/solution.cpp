class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        using pp = pair<int,pair<int,int>>;
        vector<pp>v;
        int j = 0;
        for(auto i: tasks){
            v.push_back({i[0] , {i[1] , j++}});
        }
        sort(v.begin() , v.end());
        priority_queue<pp , vector<pp>, greater<pp>>pq;
        vector<int> ans;
        int i = 0;
        long long time = v[0].first;
        while(i < v.size() or pq.size()){
            while(i < (int)v.size() and time >= v[i].first){
                pq.push({v[i].second.first , {v[i].second.second , v[i].first}});
                i++;
            }
            auto tem = pq.top();
            ans.push_back(tem.second.first);
            pq.pop();
            time += (long long)tem.first;
            if(i<(int)v.size() and time < v[i].first and pq.size() == 0){
                time = v[i].first;
            }
        }
        return ans;
    }
};