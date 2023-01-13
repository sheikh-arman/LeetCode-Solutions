#define PB push_back
class Solution {
public:
    vector<int>edj[100010];
    int len[100010];
    int ans=0;
    string str;
    void dfs(int node, int parent){
        for(int i:edj[node]){
            if(i!=parent){
                dfs(i,node);
            }
        }
        vector<int>V;
        V.PB(-1);
        V.PB(-1);
        V.PB(-1);
        for(int i:edj[node]){
            if(i!=parent){
                if(str[i]!=str[node]){
                    V[2]=len[i];
                    sort(V.begin(),V.end(),greater<int>());
                }
            }
        }
        len[node]=V[0]+1;
        int val=V[0]+V[1]+2;
        ans=max(ans,val);
        ans=max(ans,len[node]);
    }
    int longestPath(vector<int>& parent, string s) {
        int n=s.size();
        for(int i=0;i<n;i++)len[i]=0;
        str=s;
        for(int i=1;i<n;i++){
            edj[i].PB(parent[i]);
            edj[parent[i]].PB(i);
        }
        dfs(0,-1);
        return ans+1;
    }
};