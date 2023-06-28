class Solution {
public:
    double solve(vector<pair<int,double>> adj[],int start,int end,int n)
    {
        queue<pair<int,double>> q;
        vector<double> p(n,0);
        q.push({start,1});
        p[start] = 1;
        double ans = 0;

        while(!q.empty())
        {
            int node = q.front().first;
            double prob = q.front().second;
            q.pop();

            if(node==end)
            ans = max(ans,prob);

            for(auto x  : adj[node])
            {
                int nd = x.first;
                double pb = x.second;
                if(p[nd]<pb*prob)
                {
                    q.push({nd,pb*prob});
                    p[nd] = pb*prob;
                }
            }
        }
        return ans;
    }
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& sp, int start, int end) {
        vector<pair<int,double>> adj[n];

        for(int i = 0;i<e.size();i++)
        {
            adj[e[i][0]].push_back({e[i][1],sp[i]});
            adj[e[i][1]].push_back({e[i][0],sp[i]});
        }

        return solve(adj,start,end,n);  
       
    }
};