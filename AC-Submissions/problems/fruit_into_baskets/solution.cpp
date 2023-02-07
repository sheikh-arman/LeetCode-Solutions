class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int ar[100010];
        int n=fruits.size(),ans=0,cnt=0;
        for(int i=0;i<=n;i++){
            ar[i]=0;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            q.push(fruits[i]);
            if(ar[fruits[i]]==0){
                cnt++;
            }
            ar[fruits[i]]++;
            while(cnt>2){
                int fnt=q.front();
                q.pop();
                ar[fnt]--;
                if(ar[fnt]==0)cnt--;
            }
            if(cnt<3){
                ans=max(ans,(int)q.size());
            }
        }
        return ans;
    }
};