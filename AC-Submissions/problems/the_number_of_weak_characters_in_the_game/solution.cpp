class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int n=properties.size();
        vector<int> edj[100010];
        for(int i=0;i<n;i++){
            int a=properties[i][0];
            int b=properties[i][1];
            edj[a].push_back(b);
        }
        int ans=0;
        int ma_a=-1,ma_b=-1;
        for(int i=100000;i>=1;i--){
            if(((int)edj[i].size()==0)){
                continue;
            }
            if(ma_a==-1){
                ma_a=i;
                for(int j:edj[i]){
                    ma_b=max(ma_b,j);
                }
            }
            else{
                int tm=0;
                for(int j:edj[i]){
                    tm=max(tm,j);
                    if(ma_a>i&&ma_b>j){
                        ans++;
                    }
                }
                ma_a=i;
                ma_b=max(tm,ma_b);
            }
        }
        return ans;
    }
};