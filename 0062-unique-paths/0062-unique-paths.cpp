class Solution {
public:
  // Space Optimised Solution
    int uniquePaths(int m, int n) {
      vector<int> prev(n, 0);
      for(int i = 0; i < m; i++){
        vector<int> curr(n, 0);
        for(int j = 0; j < n; j++){
          if(i == 0 and j == 0) curr[j] = 1;
          else {
            int top = 0, left = 0;
            if(i > 0) top = prev[j];
            if(j > 0) left = curr[j - 1];
            curr[j] = top + left;
          }
        }
        prev = curr;
      }
      return prev[n - 1];
    }
  
  /*
  // Top Down Approach
  
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m, vector<int>(n, 0));
      for(int i = 0; i < m; i++) dp[i][0] = 1;
      for(int i = 0; i < n; i++) dp[0][i] = 1;
      for(int i = 1; i < m; i++){
        for(int j = 1; j < n; j++){
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
      }
      return dp[m - 1][n - 1];
    }
  */
  
  /*
  // Bottom Up Approach
  
    int solve(int r, int c, vector<vector<int>> &dp){
      if(r == 0 and c == 0) return 1;
      if(r < 0 or c < 0) return 0;
      if(dp[r][c] != -1) return dp[r][c];
      int top = solve(r - 1, c, dp);
      int left = solve(r, c - 1, dp);
      return dp[r][c] = top + left;
    }
    int uniquePaths(int m, int n) {
      vector<vector<int>> dp(m, vector<int>(n, -1));
	    return solve(m - 1, n - 1, dp);
    }
  */
};