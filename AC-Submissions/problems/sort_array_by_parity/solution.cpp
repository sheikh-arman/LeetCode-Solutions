class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int>V;
        for(int i:nums){
            if(i%2)V.push_back(i);
            else V.push_front(i);
        }
        nums.clear();
        for(int i:V)nums.push_back(i);
        return nums;
    }
};