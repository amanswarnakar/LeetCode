class Solution {
public:
    // Space Optimisation
    int cherryPickup(vector<vector<int>>& g) {
      int n = g.size();
      vector<vector<int>> prev(n, vector<int>(n, 0)), curr(n, vector<int>(n, 0));
      for(int r1 = 0; r1 < n; r1++){
        for(int c1 = 0; c1 < n; c1++){
          for(int r2 = 0; r2 < n; r2++){
            int c2 = r1 + c1 - r2;
            int res = -1e5;
            if(c2 < 0 or c2 >= n) continue;
            if(min(r1, r2) < 0 or min(c1, c2) < 0 or g[r1][c1] == -1 or g[r2][c2] == -1) 
              res = -1e5;
            else if(r1 == 0 and c1 == 0){
              curr[c1][r2] = g[r1][c1];
              continue;
            } else {
              int temp = -1e5;
              res = g[r1][c1];
              if(r1 != r2) res += g[r2][c2];
              if(r1 > 0 and r2 > 0)
                temp = max(temp, prev[c1][r2 - 1]);
              if(c1 > 0 and c2 > 0)
                temp = max(temp, curr[c1 - 1][r2]);
              if(r1 > 0 and c2 > 0)
                temp = max(temp, prev[c1][r2]);
              if(c1 > 0 and r2 > 0) 
                temp = max(temp, curr[c1 - 1][r2 - 1]);

              res += temp;
            }
            curr[c1][r2] = res;
          }
          prev = curr;
        }
      }
      return max(prev[n - 1][n - 1], 0);
    }
  
    /*
    // Tabulation 
    
    int cherryPickup(vector<vector<int>>& g) {
      int n = g.size(), ans = 0;
      vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(n, 0)));
      for(int r1 = 0; r1 < n; r1++){
        for(int c1 = 0; c1 < n; c1++){
          for(int r2 = 0; r2 < n; r2++){
            int c2 = r1 + c1 - r2;
            long long res = -1e5;
            if(c2 < 0 or c2 >= n) continue;
            if(min(r1, r2) < 0 or min(c1, c2) < 0 or g[r1][c1] == -1 or g[r2][c2] == -1) 
              res = -1e5;
            else if(r1 == 0 and c1 == 0){
              dp[r1][c1][r2] = g[r1][c1];
              continue;
            } else {
              long long temp = -1e5;
              res = g[r1][c1];
              if(r1 != r2) res += g[r2][c2];
              if(r1 > 0 and r2 > 0)
                temp = max(temp, dp[r1 - 1][c1][r2 - 1]);
              if(c1 > 0 and c2 > 0)
                temp = max(temp, dp[r1][c1 - 1][r2]);
              if(r1 > 0 and c2 > 0)
                temp = max(temp, dp[r1 - 1][c1][r2]);
              if(c1 > 0 and r2 > 0) 
                temp = max(temp, dp[r1][c1 - 1][r2 - 1]);

              res += temp;
            }
            dp[r1][c1][r2] = res;
          }
        }
      }
      return max(dp[n - 1][n - 1][n - 1], 0ll);
    }
    */
  
    /*
    // Memoization
    
    int solve(int r1, int c1, int r2, vector<vector<int>> &g, vector<vector<vector<int>>> &dp){
      int c2 = r1 + c1 - r2;
      if(min(r1, r2) < 0 or min(c1, c2) < 0 or g[r1][c1] == -1 or g[r2][c2] == -1) 
        return -1e8;
      if(r1 == 0 and c1 == 0) return g[r1][c1];
      if(dp[r1][c1][r2] != -1) return dp[r1][c1][r2];
      int res = g[r1][c1], temp = 0;
      if(r1 != r2) res += g[r2][c2];
      
      temp = max(solve(r1 - 1, c1, r2 - 1, g, dp), solve(r1, c1 - 1, r2, g, dp));
      temp = max(temp, solve(r1 - 1, c1, r2, g, dp));
      temp = max(temp, solve(r1, c1 - 1, r2 -1, g, dp));
      
      res += temp;
      return dp[r1][c1][r2] = res;
    }
  
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size(), ans = 0;
      vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(m, -1)));
      ans = solve(m - 1, n - 1, m - 1, g, dp);
      return max(ans, 0);
    }
    */
};