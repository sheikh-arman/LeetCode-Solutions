class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int>V;
        bool ck=0;
        for(int i:nums){
            int pos=lower_bound(V.begin(),V.end(),i)-V.begin();
            if(pos>=(int)V.size()){
                V.push_back(i);
            }
            else{
                V[pos]=i;
            }
            if(V.size()>2){
                ck=1;break;
            }
        }
        return ck;
    }
};