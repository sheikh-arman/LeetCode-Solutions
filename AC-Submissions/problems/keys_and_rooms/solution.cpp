class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int ar[rooms.size()];
        for(int i=0;i<n;i++)ar[i]=0;
        queue<int>q;
        q.push(0);
        while(!q.empty()){
            int val=q.front();
            q.pop();
            ar[val]=1;
            for(int i:rooms[val]){
                if(ar[i]==0){
                    q.push(i);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(ar[i]==0)return 0;
        }
        return 1;
    }
};