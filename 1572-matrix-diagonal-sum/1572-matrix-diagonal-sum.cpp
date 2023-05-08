class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
      int ans = 0, j = 0, n = mat.size();
      for(int i = 0; i < n; i++){
        if(j != n - j - 1) ans += mat[i][j] + mat[i][n-j-1];
        else ans += mat[i][j];
        j++;
      }
      return ans;
    }
};