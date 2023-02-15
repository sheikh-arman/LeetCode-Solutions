class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        reverse(num.begin(),num.end());
        int n=num.size(),i=0,carry=0;
        while(k){
            carry+=k%10;
            if(i<n){
                carry+=num[i];
                num[i]=carry%10;
            }
            else{
                num.push_back(carry%10);
            }
            carry/=10;
            k/=10;
            i++;
        }
        while(i<n){
            carry+=num[i];
            num[i]=carry%10;    
            i++;
            carry/=10;
        }
        if(carry){
            if(i<n){
            carry+=num[i];
            num[i]=carry%10;
        }
        else{
            num.push_back(carry%10);
        }
        }
        reverse(num.begin(),num.end());
        return num;
    }
};