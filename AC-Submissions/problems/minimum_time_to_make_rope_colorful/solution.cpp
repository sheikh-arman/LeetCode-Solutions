class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        vector<int>sum,ma,str;
        int n=colors.size();
        for(int i=0;i<n;i++){
            if((int)sum.size()==0){
                str.push_back(colors[i]-'a');
                sum.push_back(neededTime[i]);
                ma.push_back(neededTime[i]);
            }
            else{
                int siz=sum.size();
                if(str[siz-1]==colors[i]-'a'){
                    ma[siz-1]=max(ma[siz-1],neededTime[i]);
                    sum[siz-1]=sum[siz-1]+neededTime[i];
                }
                else{
                    str.push_back(colors[i]-'a');
                    sum.push_back(neededTime[i]);
                    ma.push_back(neededTime[i]);
                }
            }
        }
        int siz=sum.size();
        int ans=0;
        for(int i=0;i<siz;i++){
            ans+=sum[i]-ma[i];
        }
        return ans;
    }
};