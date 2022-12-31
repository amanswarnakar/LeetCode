class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      if(v[0][0] or v[m - 1][n - 1]) return 0;
      vector<vector<long long int>> dp(m, vector<long long int>(n, 0));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j]) v[i][j] = 0;
          else v[i][j] = 1;
        }
      }
      for(int i = m - 1; i >= 0; i--){
        if(v[i][n - 1]) dp[i][n - 1] = 1;
        else break;
      }
      for(int i = n - 1; i >= 0; i--){
        if(v[m - 1][i]) dp[m - 1][i] = 1;
        else break;
      }
      for(int i = m - 2; i >= 0; i--){
        for(int j = n - 2; j >= 0; j--){
          dp[i][j] = dp[i + 1][j] * v[i + 1][j] + dp[i][j + 1] * v[i][j + 1];
          // dp[i][j] *= v[i][j];
        }
      }
      return dp[0][0];
    }
};