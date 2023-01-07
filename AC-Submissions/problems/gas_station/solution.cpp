class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        for(int i=0;i<n;i++){
            gas.push_back(gas[i]);
            cost.push_back(cost[i]);
        }
        int m=gas.size();
        int pos=0;
        int res=-1;
        for(int i=0;i<n;i++){
            pos=i;
            long long ans=gas[i];
            while(pos<m&&ans>=cost[pos]&&pos-i<=n){
                ans-=cost[pos];
                pos++;
                ans+=gas[pos%m];
            }
            if(pos-i>=n){
                res=i;break;
            }
            i=pos;
        }
        return res;
    }
};