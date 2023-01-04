class Solution {
public:
    int mem[100010];
    int dp(int pos,vector<int>& tasks){
        if(pos>=tasks.size())return 0;
        if(mem[pos]!=-1)return mem[pos];
        int ans=1000000;
        int n=tasks.size();
        if(pos+1>=n)return ans;
        if(tasks[pos]==tasks[pos+1]){
            ans=1+dp(pos+2,tasks);
        }
        if(pos+2<n){
            if(tasks[pos+1]==tasks[pos]&&tasks[pos]==tasks[pos+2]){
                ans=min(ans,dp(pos+3,tasks)+1);
            }
        }
        return mem[pos]=ans;   
    }
    int minimumRounds(vector<int>& tasks) {
        sort(tasks.begin(),tasks.end());
        int n=tasks.size();
        for(int i=0;i<=n;i++){
            mem[i]=-1;
        }
        int ans=dp(0,tasks);
        if(ans>100000)ans=-1;
        return ans;
    }
};