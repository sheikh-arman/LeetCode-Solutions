//later
class Solution {
public:
    // multiset approach
    vector<int> findOriginalArray(vector<int>& changed) {
       
        if (changed.size() & 1) return {};
        vector<int> ans;
       
        multiset<int> s(changed.begin(), changed.end());
       
        while (s.size()) {
             int smallest = *s.begin();
            ans.push_back(smallest);
           
            s.erase(s.begin());
          
            if (s.find(smallest * 2) == s.end()) return {};

            else s.erase(s.find(smallest * 2));   
        }
        return ans;
    }
};