class Solution {
public:
    int n;
    vector<vector<int>>V;
    vector<int>path;
    void dfs(int node, int parent, vector<vector<int>>& graph){
        if(node==n-1){
            V.push_back(path);
            return;
        }
        for(int i:graph[node]){
            if(i!=parent){
                path.push_back(i);
                dfs(i, node,graph);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n=graph.size();
        path.push_back(0);
        dfs(0,-1,graph);
        return V;
    }
};