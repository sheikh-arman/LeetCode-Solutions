class Solution {
public:
    int convolute(vector<vector<int>>& img1, vector<vector<int>>& kernel, int xShift, int yShift){
        int result = 0;
        
        for(int i=0; i<img1.size(); i++){
            for(int j=0; j<img1.size(); j++){
                result += img1[i][j] * kernel[i + xShift][j + yShift];
            }
        }
        return result;
    }
    
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<vector<int>> kernel(3*n-2, vector<int>(3*n-2));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                kernel[i+n-1][j+n-1] = img2[i][j];
            }
        }
        
        int maxOverlaps = 0;
        for(int i=0; i<2*n-1; i++){
            for(int j=0; j<2*n-1; j++){
                maxOverlaps = max(maxOverlaps, convolute(img1, kernel, i, j));
            }
        }
        
        return maxOverlaps;
    }
};