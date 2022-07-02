class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long hor=0,ver=0,pre=0,ans;
        int n=horizontalCuts.size();
        for(int i=0;i<n;i++){
            hor=max(hor,horizontalCuts[i]-pre);
            pre=horizontalCuts[i];
        }
        hor=max(hor,(long long)(h-pre));
        n=verticalCuts.size();
        pre=0;
        for(int i=0;i<n;i++){
            ver=max(ver,(long long)(verticalCuts[i]-pre));
            pre=verticalCuts[i];
        }
        ver=max(ver,(long long)(w-pre));
        //cout<<hor<<" "<<ver<< " hi\n";
        ans=ver*hor;
        ans%=1000000007;
        return (int)ans;
    }
};