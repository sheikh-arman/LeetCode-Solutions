class Solution {
public:
    bool equalFrequency(string word) {
        int ar[30];
        for(int i=0;i<26;i++)ar[i]=0;
        for(int i=0;word[i]!='\0';i++){
            ar[word[i]-'a']++;
        }
        bool ck=0;
        vector<int>V;
        for(int i=0;i<26;i++){
            if(ar[i]>0){
                V.push_back(ar[i]);
            }   
        }
        int siz=V.size();
        for(int i=0;i<siz;i++){
            V[i]-=1;
            int ck2=1;
            for(int j=1;j<siz;j++){
                if(V[i]==0){
                    if(j-1==i||j==i)continue;
                }
               if(V[j]!=V[j-1]){
                    ck2=0;break;
                }
                
            }
            if(V[i]==0){
                if(i-1>=0&&i+1<siz){
                    if(V[i-1]!=V[i+1])ck2=0;
                }
            }
            if(ck2==1){
                //cout<<i<<" t\n";
                ck=1;break;
            }
            V[i]+=1;
        }
        return ck;
    }
};