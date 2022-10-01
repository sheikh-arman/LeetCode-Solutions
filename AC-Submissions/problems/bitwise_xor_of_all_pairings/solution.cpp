class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int siz=nums1.size();
        int siz2=nums2.size();
        int Xor=0;
        if(siz2%2!=0){
            for(int i:nums1)Xor^=i;
        }
        if(siz%2==1){
            for(int i:nums2)Xor^=i;
        }
        return Xor;
    }
};