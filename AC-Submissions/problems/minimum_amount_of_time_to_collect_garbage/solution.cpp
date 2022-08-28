class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int p=-1,g=-1,m=-1;
        int cntp=0,cntg=0,cntm=0;
        int n=garbage.size();
        for(int i=0;i<n;i++){
            string s=garbage[i];
            for(int j=0;s[j]!='\0';j++){
                 if(s[j]=='P'){
                     cntp++;
                      p=i;
                  }
                  if(s[j]=='M'){
                      cntm++;
                      m=i;
                  }
                  if(s[j]=='G'){
                    cntg++;
                    g=i;
                  }
            }
        }
        n=travel.size();
        for(int i=1;i<n;i++){
            travel[i]+=travel[i-1];
        }
        int ans=0;
        ans=cntp+cntg+cntm;
        if(p>0){
            ans+=travel[p-1];
        }
        if(g>0){
            ans+=travel[g-1];
        }
        if(m>0){
            ans+=travel[m-1];
        }
        return ans;
    }
};