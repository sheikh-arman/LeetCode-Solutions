class Solution {
public:
    int countOdds(int low, int high) {
        int ans=(high+1)/2;
        if(low>0){
            ans-=(low)/2;
        }
        return ans;
    }
};