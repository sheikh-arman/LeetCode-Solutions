class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ans=0;
        sort(costs.begin(),costs.end());
        for(int i:costs){
            if(i<=coins){
                ans++;
                coins-=i;
            }
        }
        return ans;
    }
};