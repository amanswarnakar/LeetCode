class Solution {
public:
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector<vector<int>> prev(n, vector<int>(n, 0)), curr(n, vector<int>(n, 0));
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i == j) prev[i][j] = g[m - 1][i];
          else prev[i][j] = g[m - 1][i] + g[m - 1][j];
        }
      }
      
      for(int r = m - 2; r >= 0; r--){
        for(int c1 = 0; c1 < n; c1++){
          for(int c2 = 0; c2 < n; c2++){
            
            int temp = -1e8;
            for(int i = -1; i < 2; i++){
              for(int j = -1; j < 2; j++){
                int val = g[r][c1];
                if(c1 != c2) val += g[r][c2];
                if(c1 + i >= 0 and c1 + i < g[0].size() and c2 + j >= 0 and c2 + j < g[0].size())
                  val += prev[c1 + i][c2 + j];
                else val = -1e8;
                temp = max(temp, val);
              }
            }
            curr[c1][c2] = temp;
          }
        }
        prev = curr;
      }
      return prev[0][n - 1];
    }
  
    /*
    // Tabulation 
    
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, 0)));
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          if(i == j) dp[m - 1][i][j] = g[m - 1][i];
          else dp[m - 1][i][j] = g[m - 1][i] + g[m - 1][j];
        }
      }
      
      for(int r = m - 2; r >= 0; r--){
        for(int c1 = 0; c1 < n; c1++){
          for(int c2 = 0; c2 < n; c2++){
            
            int temp = -1e8;
            for(int i = -1; i < 2; i++){
              for(int j = -1; j < 2; j++){
                int val = g[r][c1];
                if(c1 != c2) val += g[r][c2];
                if(c1 + i >= 0 and c1 + i < g[0].size() and c2 + j >= 0 and c2 + j < g[0].size())
                  val += dp[r + 1][c1 + i][c2 + j];
                else val = -1e8;
                temp = max(temp, val);
              }
            }
            dp[r][c1][c2] = temp;
          }
        }
      }
      return dp[0][0][n - 1];
    }
    */
    
    /*
    // Memoization
    
    int solve(int c1, int c2, int r, vector<vector<int>> &g, vector<vector<vector<int>>> &dp){
      if(min(c1, c2) < 0 or max(c1, c2) == g[0].size()) return 0;
      if(r == g.size() - 1)
        return c1 == c2 ? g[r][c1] : g[r][c1] + g[r][c2];
      if(dp[r][c1][c2] != -1) return dp[r][c1][c2];
      int temp = 0;
      for(int i = -1; i < 2; i++){
        for(int j = -1; j < 2; j++){
          temp = max(temp, solve(c1 + i, c2 + j, r + 1, g, dp));
        }
      }
      int res = c1 == c2 ? g[r][c1] + temp : g[r][c1] + g[r][c2] + temp;
      return dp[r][c1][c2] = res;
    }
    int cherryPickup(vector<vector<int>>& g) {
      int m = g.size(), n = g[0].size();
      vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(n, -1)));
      int ans = solve(0, n - 1, 0, g, dp);
      return ans;
    }
    */
};