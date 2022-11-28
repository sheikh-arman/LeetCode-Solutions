class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int win[200010];
        int mat[200010];
        int loss[200010];
        for(int i=0;i<=200000;i++){win[i]=0;loss[i]=0;mat[i]=0;}
        int n=matches.size();
        for(int i=0;i<n;i++){
            win[matches[i][0]]++;
            mat[matches[i][0]]++;
            loss[matches[i][1]]++;   
            mat[matches[i][1]]++;   
        }
        vector<int>V1,V2;
        for(int i=0;i<=200000;i++){
            if(win[i]==mat[i]&&mat[i]!=0){
                V1.push_back(i);
            }
            if(loss[i]==1)V2.push_back(i);
        }
        vector<vector<int>>V;
        V.push_back(V1);
        V.push_back(V2);
     return V;
    }
};