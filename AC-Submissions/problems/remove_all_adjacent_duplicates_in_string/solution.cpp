class Solution {
public:
    string removeDuplicates(string s) {
        string ans;
        int n=s.size();
        stack<char>stk;
        for(int i=0;i<n;i++){
            if(stk.size()){
               // cout<<i<<" "<<stk.top()<<" "<<s[i]<<" x\n";
                if(stk.top()==s[i])stk.pop();
                else stk.push(s[i]);
            }
            else{
                stk.push(s[i]);
            }
        }
        while(!stk.empty()){
            ans+=stk.top();
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};