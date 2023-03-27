class Solution {
public:
    int minPathSum(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      vector<vector<int>> dp(m + 1, vector<int>(n + 1, INT_MAX));
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          dp[i + 1][j + 1] = v[i][j];
        }
      }
      for(int i = 1; i < m + 1; i++){
        for(int j = 1; j < n + 1; j++){
          if(i == 1 and j == 1) continue;
          dp[i][j] += min(dp[i - 1][j], dp[i][j - 1]);
        }
      }
      return dp[m][n];
    }
};