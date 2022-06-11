class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=spells.size();
        int m=potions.size();
        for(int i=0;i<n;i++){
            int pos=lower_bound(potions.begin(),potions.end(),success/spells[i]+(success%spells[i]!=0))-potions.begin();
            spells[i]=m-pos;
        }
        return spells;
    }
};