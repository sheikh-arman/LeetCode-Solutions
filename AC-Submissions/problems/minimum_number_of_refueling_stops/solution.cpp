class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        priority_queue<int>pq;
        int ans=0;
        vector<int>V;
        V.push_back(target);
        V.push_back(0);
        stations.push_back(V);
        int n=stations.size();
        for(int i=0;i<n;i++){
            int pos=stations[i][0];
            int fuel=stations[i][1];
            if(startFuel>=target){
                break;
            }
            if(pos<=startFuel){
                pq.push(fuel);
            }
            else{
                while(!pq.empty()){
                    int tp=pq.top();
                    pq.pop();
                    startFuel+=tp;
                    ans++;
                    if(startFuel>=pos){
                        break;
                    }
                }
                 if(startFuel<pos){
                        ans=-1;break;
                }
                else{
                     pq.push(fuel);
                }
            }
        }
        return ans;
    }
};