class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size(), m = mat[0].size();
        if(n*m/r!=c) {
            return mat;
        }
        
        int i1=0, j1=0, i2=0, j2=0;
        vector<vector<int>> ans(r, vector<int>(c));
        for(i1=0;i1<n;i1++) {
            for(j1=0;j1<m;j1++) {
                ans[i2][j2] = mat[i1][j1];
                j2++;
                if(j2==c) {
                    i2++;
                    j2=0;
                }
            }
        }
        return ans;
    }
};