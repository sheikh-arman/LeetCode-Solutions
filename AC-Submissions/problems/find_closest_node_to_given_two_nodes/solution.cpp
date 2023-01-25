class Solution {
public:
    int label1[100010];
    int label2[100010];
    int color[100010];
    vector<int>edj[100010];
    void dfs(int node,int status){
        color[node]=1;
        for(int i:edj[node]){
            if(color[i]==0){
                color[i]=1;
                if(status==1){
                    label1[i]=label1[node]+1;
                }
                else{
                    label2[i]=label2[node]+1;
                }
                dfs(i,status);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        for(int i=0;i<=100000;i++){
            color[i]=0;
            label1[i]=100000000;
            label2[i]=100000000;
        }
        label1[node1]=0;
        label2[node2]=0;
        int n=edges.size();
        for(int i=0;i<n;i++){
            if(edges[i] != -1){
                edj[i].push_back(edges[i]);
            }
        }
        dfs(node1,1);
        for(int i=0;i<=100000;i++){
            color[i]=0;
        }
        dfs(node2,2);
        int mi=10000000,node=-1;
        for(int i=0;i<n;i++){
            int total=max(label1[i],label2[i]);
            if(total<mi){
                mi=total;
                node=i;
            }
            if(total==mi){
                node=min(node,i);
            }
        }
        return node;
    }
};