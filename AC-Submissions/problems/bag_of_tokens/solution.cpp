class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        int ans=0,currnt=0;
        int left=0,right=tokens.size()-1;
        while(left<=right){
            ans=max(ans,currnt);
            if(tokens[left]<=power){
                power-=tokens[left];
                currnt++;left++;
            }
            else{
                if(currnt>0){
                    currnt--;
                    power+=tokens[right--];
                }
                else{
                    break;
                }
                
            }
            ans=max(ans,currnt);
        }
        return ans;
    }
};