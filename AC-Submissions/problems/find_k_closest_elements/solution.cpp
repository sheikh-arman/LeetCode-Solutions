class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>V;
        for(int i:arr){
            V.push_back({abs(i-x),i});
        }
        sort(V.begin(),V.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(V[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};