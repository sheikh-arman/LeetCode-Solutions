class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int ar[n][n];
        int x=0,y=0;
        for(int i=0;i<n;i++){
            y=0;
            for(int j=n-1;j>=0;j--){
                ar[x][y++]=matrix[j][i];
            }
            x++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j]=ar[i][j];
            }
        }
    }
};