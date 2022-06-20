class Solution {
public:
    bool static cmp(string a,string b){
        return a.size()>b.size();
    }
    int ar[100000][30],cnt=1;
    int trie(string s){
        int ck=1;
        int n=s.size(),curr=0;
        for(int i=0;i<n;i++){
            int val=s[i]-'a';
            if(ar[curr][val]==0){
                ar[curr][val]=cnt++;
                ck=0;
            }
            curr=ar[curr][val];
        }
        int ans=0;
        if(ck==0){
            ans=s.size()+1;
        }
        return ans;
    }
    int minimumLengthEncoding(vector<string>& words) {
        cnt=1;
        for(int i=0;i<10;i++){
            for(int j=0;j<28;j++){
                ar[i][j]=0;
            }
        }
        sort(words.begin(),words.end(),cmp);
        int n=words.size();
        int ans=0;
        for(int i=0;i<n;i++){
            reverse(words[i].begin(),words[i].end());
            ans+=trie(words[i]);
        }
        return ans;
    }
};