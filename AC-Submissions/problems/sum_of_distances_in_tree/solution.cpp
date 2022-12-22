class Solution {
public:
    vector<int>edj[30010];
    int cnt[30010],dist[30010];
    void dfs(int node,int parent){
        cnt[node]=1;
        dist[node]=0;
        for(int i:edj[node]){
            if(cnt[i]==0){
                dfs(i,node);
                cnt[node]+=cnt[i];
            }
        }
        for(int i:edj[node]){
            if(i!=parent){
                dist[node]+=cnt[i]+dist[i];
            }
        }
    }
    int ans_dist[30010];
    void dfs_cal(int node,int parent){
        int pa_dist,pa_cnt,node_dist, node_cnt;
        if(parent==-1)ans_dist[node]=dist[node];
        else{
            pa_dist=dist[parent];
            pa_cnt=cnt[parent];
            dist[parent]=0;
            cnt[parent]=1;
            for(int i:edj[parent]){
                if(i!=node){
                    dist[parent]+=dist[i]+cnt[i];
                    cnt[parent]+=cnt[i];
                }
            }
            node_dist=dist[node];
            node_cnt=cnt[node];
            dist[node]=0;
            cnt[node]=1;
            for(int i:edj[node]){
                cnt[node]+=cnt[i];
                dist[node]+=dist[i]+cnt[i];
            }
            ans_dist[node]=dist[node];
            
        }
        for(int i:edj[node]){
            if(i!=parent){
                dfs_cal(i,node);
            }
        }
        if(parent!=-1){
            dist[parent]=pa_dist;
            cnt[parent]=pa_cnt;
            dist[node]=node_dist;
            cnt[node]=node_cnt;
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            edj[u].push_back(v);
            edj[v].push_back(u);
        }
        dfs(0,-1);
        dfs_cal(0,-1);
        vector<int>V;
        for(int i=0;i<n;i++){
            V.push_back(ans_dist[i]);
        }
        return V;
    }
};