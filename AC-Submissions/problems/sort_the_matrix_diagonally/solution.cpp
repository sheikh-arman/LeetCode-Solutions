class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> v;

    for (int row=0; row<m; row++)   //starting diagonal from rowside(0 to m-1)
    {
         
        for(int i=row,j=0; i<m && j<n; i++, j++)
            v.push_back(mat[i][j]);
        sort(v.begin(),v.end());
        for(int i=row,j=0; i<m && j<n; i++, j++)
            mat[i][j]= v[j];
        v.clear();
        
    }
    for (int col=1; col<n; col++)  //starting diagonal from columnside(1 to n-1)
    {
        
        for(int i=0,j=col; i<m && j<n; i++, j++)
            v.push_back(mat[i][j]);
        sort(v.begin(),v.end());
        for(int i=0,j=col; i<m && j<n; i++, j++)
            mat[i][j]= v[i];
         v.clear();
    }
    return mat;
    }
};