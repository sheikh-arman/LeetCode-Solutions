class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int ar[100010];
        for(int i=0;i<=100000;i++)ar[i]=0;
        for(int i:arr){
            ar[i]++;
        }
        int n=arr.size();
        int cnt=0,sum=0;
        vector<int>V;
        for(int i=0;i<=100000;i++){
            if(ar[i]>0){
                V.push_back(ar[i]);
            }
        }
        sort(V.begin(),V.end(),greater<int>());
        int siz=V.size();
        for(int i=0;i<siz;i++){
            sum+=V[i];
            cnt++;
            if(sum*2>=n)break;
        }
        return cnt;
    }
};