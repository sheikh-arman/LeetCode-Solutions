class Solution {
public:
    int ar[100010][28];
    vector<int>edj[100010];
    string lbl;
    void dfs(int node,int parent){
        for(int i:edj[node]){
            if(i!=parent){
                dfs(i,node);
            }
        }
        for(int i:edj[node]){
            for(int j=0;j<26;j++){
                ar[node][j]+=ar[i][j];
            }
        }
        ar[node][lbl[node]-'a']++;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(int i=0;i<=n;i++){
            for(int j=0;j<26;j++){
                ar[i][j]=0;
            }
        }
        int m=edges.size();
        for(int i=0;i<m;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            edj[u].push_back(v);
            edj[v].push_back(u);
        }
        lbl=labels;
        dfs(0,-1);
        vector<int>V;
        for(int i=0;i<n;i++){
            V.push_back(ar[i][lbl[i]-'a']);
        }
        return V;
    }
};