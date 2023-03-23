class Solution {
public:
    vector<int> visited;
    
    void dfs(int node ,vector<vector<int>> &graph){
        //base case
        if(visited[node]) return;
        visited[node] = 1;
        
        for(auto it :graph[node]){
            dfs(it,graph);
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
     
        visited.resize(n,0);
        vector<vector<int>>graph(n);
        
        int total_edges = connections.size();
        int components=0;
        
        //create adjecency list
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                components++;
                //visit all nodes which are connected to node 'i'
                dfs(i,graph);
            }
        }
        
        
        if(components <2 ) return 0;
        
        //we need atleast n-1 edges to connect all the nodes
        if(total_edges >=n-1) return components-1;
        return -1;
    }
};