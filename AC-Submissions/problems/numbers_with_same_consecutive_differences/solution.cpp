class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        queue<pair<int,int>>q;
        vector<int>V;
        for(int i=1;i<10;i++){
            q.push({i,1});
        }
        while(!q.empty()){
            int val=q.front().first;
            int len=q.front().second;
            q.pop();
            if(len==n){
                V.push_back(val);
            }
            else{
                int num=val%10;
                int tm=num+k;
                if(tm<10){
                    q.push({(val*10)+tm,len+1});
                }
                tm=num-k;
                if(tm>=0&&k!=0){
                    q.push({(val*10)+tm,len+1});
                }
                
            }
        }
        return V;
    }
};