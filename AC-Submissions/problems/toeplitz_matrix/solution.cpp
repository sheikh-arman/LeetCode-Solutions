class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        set<int>st;
        bool ck=1;
        for(int j=0;j<m;j++){
            int i=0;
            int k=j;
            st.clear();
            while(i<n&&k<m){
                st.insert(matrix[i][k]);
                i++;k++;
            }
            ck&=(st.size()==1);
        }
        for(int i=1;i<n;i++){
            int j=0;
            int k=i;
            st.clear();
            while(j<m&&k<n){
                st.insert(matrix[k][j]);
                k++;
                j++;
            }
            ck&=(st.size()==1);
        }
        return ck;
    }
};