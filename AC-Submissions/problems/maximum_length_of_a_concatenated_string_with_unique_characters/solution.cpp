class Solution {
public:
    int n;
    int total;
    std::vector<int> vBit;
    std::vector<int> prefix;
    std::vector<std::vector<int>> dp;

    int maxLength(vector<string>& arr) {
        n = arr.size();
        
        //create vBit: the hash vector of arr[i]'s
        //vBit[i] = hash value of arr[i]
        vBit.resize(n, 0);
        std::bitset<26> temp;
        for (int i=0; i<n; i++){
            temp = 0;
            for (int j=0; j<arr[i].size(); j++){
                if (temp[arr[i][j]-'a']==1){
                    //arr[i] should be of unique characters
                    //otherwise, vBit[i] is set to be zero 
                    temp = 0;
                    break;
                }
                temp[arr[i][j]-'a'] = 1;
            }
            vBit[i] = temp.to_ulong();
        }
        
        //set up prefix and total
        prefix.resize(n, 0);
        prefix[0] = arr[0].size();
        for (int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + arr[i].size();
        }
        total = prefix[n-1];
        
        //dynamic programming
        dp.resize(total+1, std::vector<int>{});
        dp[0].push_back(0); //string: ""
        int currLength;
        
        for (int i=0; i<n; i++){
            currLength = arr[i].size();
            if (vBit[i]==0) continue;
            
            for (int x=0; x<=prefix[i]; x++){
                if (dp[x].size()==0) continue;
                
                // vBit[i]&y : check if the concatenation y contains 
                //             any letters found in arr[i]
                // if not, we can extend y to (vBit[i]|y)
                for (int y: dp[x]){
                    if ((vBit[i]&y)==0){
                        dp[x+currLength].push_back(vBit[i]|y);
                    }
                }
            }    
            
        }
        
        //find out max dp[x] which is non empty
        for (int x=total; x>=0; x--){
            if (dp[x].size()>0) return x;
        }
        
        return 0;
    }
};