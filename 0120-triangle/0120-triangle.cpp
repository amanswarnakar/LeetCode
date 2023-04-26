class Solution {
public:
    int minimumTotal(vector<vector<int>>& v) {
      int n = v.size();
      vector<int> prev(n, 0);
      for(int i = n - 1; i >= 0; i--){
        vector<int> curr(n, 0);
        for(int j = 0; j < i + 1; j++){
          if(i == n - 1) curr[j] = v[i][j];
          else {
            int left = prev[j], right = prev[j + 1];
            curr[j] = v[i][j] + min(left, right);
          }
        }
        prev = curr;
      }
      return prev[0];
    }
  
  /*
    // Tabulation
  
    int minimumTotal(vector<vector<int>>& v) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(n, 1e9));
      for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i + 1; j++){
          if(i == n - 1) dp[i][j] = v[i][j];
          else {
            int left = dp[i + 1][j], right = dp[i + 1][j + 1];
            dp[i][j] = v[i][j] + min(left, right);
          }
        }
      }
      return dp[0][0];
    }
  */
  
  /*
  // Better Memoization (Top Down Approach)
  
    int solve(int r, int c, vector<vector<int>> &v, vector<vector<int>> &dp){
      if(r == v.size() - 1) return v[r][c];
      if(dp[r][c] != -1) return dp[r][c];
      int left = solve(r + 1, c, v, dp);
      int right = solve(r + 1, c + 1, v, dp);
      return dp[r][c] = v[r][c] + min(left, right);
    }
  
    int minimumTotal(vector<vector<int>>& v) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(n, -1));
      return solve(0, 0, v, dp);
    }
  */
  
  
  /*
  // Memoization (Bottom Up)
    int solve(int r, int idx, vector<vector<int>> &v, vector<vector<int>> &dp){
      if(r == 0) return v[0][0];
      if(idx < 0 or idx == v[r].size()) return 1e9;
      if(dp[r][idx] != -1) return dp[r][idx];
      int topLeft = 1e9, topRight = 1e9;
      topLeft = solve(r - 1, idx - 1, v, dp);
      topRight = solve(r - 1, idx, v, dp);
      return dp[r][idx] = v[r][idx] + min(topLeft, topRight);
    }
  
    int minimumTotal(vector<vector<int>>& v) {
      int n = v.size();
      int ans = INT_MAX;
      vector dp(n, vector<int>(n, -1));
      for(int i = 0; i < n; i++){
        int temp = solve(n - 1, i, v, dp);
        ans = min(ans, temp);
      }
      return ans;
    }
  */
};