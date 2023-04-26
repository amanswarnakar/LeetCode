class Solution {
public:
    // Tabulation
  
    int minFallingPathSum(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size(), ans = 0;
      vector<vector<int>> dp(m, vector<int>(n, 0));
      for(int i = 0; i < n; i++) dp[m - 1][i] = v[m - 1][i];
      for(int i = m - 2; i >= 0; i--){
        for(int j = 0; j < n; j++){
          int left = 1e9, down = dp[i + 1][j], right = 1e9;
          if(j > 0) left = dp[i + 1][j - 1];
          if(j < n - 1) right = dp[i + 1][j + 1];
          dp[i][j] = v[i][j] + min(left, min(down, right));
        }
      }
      // for(int &i: dp[0]) ans = min(ans, i);
      // return ans;
      return *min_element(dp[0].begin(), dp[0].end());
    }
  
    /*
    // Memoization 
    
    int solve(int r, int c, vector<vector<int>> &g, vector<vector<int>> &dp){
      if(c < 0 or c == g[0].size()) return 1e9;
      if(r == 0) return g[0][c];
      if(dp[r][c] != -1) return dp[r][c];
      int top = solve(r - 1, c, g, dp);
      int topLeft = solve(r - 1, c - 1, g, dp);
      int topRight = solve(r - 1, c + 1, g, dp);
      return dp[r][c] = g[r][c] + min(top, min(topLeft, topRight));
    }
  
    int minFallingPathSum(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      int ans = INT_MAX;
      vector<vector<int>> dp(m, vector<int>(n, -1));
      for(int i = 0; i < n; i++){
        ans = min(ans, solve(m - 1, i, g, dp));
      }
      return ans;
    }
    */
};