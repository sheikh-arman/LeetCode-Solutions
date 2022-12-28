class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum=0;
        priority_queue<int>pq;
        for(int i:piles){
            pq.push(i);
            sum+=i;
        }
        while(k--){
            int val=pq.top();
            pq.pop();
            int tm=(val/2);
            val-=tm;
            
            sum-=tm;
           // cout<<tm<<" x\n";
            pq.push(val);
        }
        return sum;
    }
};