class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        string s1=p;
        string s2=s;
        vector<int>V;
        int n=s1.size();
        int m=s2.size();
        if(m<n)return V;
        int ar[30],ar2[30];
        for(int i=0;i<26;i++){
            ar[i]=0;
            ar2[i]=0;
        }
        for(int i=0;i<n;i++){
            ar[s1[i]-'a']++;
        }
        int left=0,right=0;
        queue<char>q;
        for(int i=0;i<n;i++){
            q.push(s2[i]);
            ar2[s2[i]-'a']++;
        }
        for(int i=n;i<m;i++){
            int ck=1;
            for(int j=0;j<26;j++){
                if(ar[j]!=ar2[j]){
                    ck=0;
                }
            }
            if(ck)V.push_back(i-n);
            char ch=q.front();
            q.pop();
            ar2[ch-'a']--;
            ar2[s2[i]-'a']++;
            q.push(s2[i]);
        }
        int ck=1;
        for(int j=0;j<26;j++){
            if(ar[j]!=ar2[j]){
                ck=0;
            }
        }
        if(ck)V.push_back(m-n);
        return V;
    }
};