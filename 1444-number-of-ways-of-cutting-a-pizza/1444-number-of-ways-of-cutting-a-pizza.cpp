class Solution {
public:
 
    int ways(vector<string>& v, int k) {
      int mod = 1000000007, m = v.size(), n = v[0].size();
      vector apples(m + 1, vector<int>(n + 1, 0));
      vector dp(k, vector(m, vector<int>(n)));

      for(int i = m - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
          apples[i][j] = (v[i][j] == 'A') + apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
          dp[0][i][j] = apples[i][j] > 0;
        }
      }
      
      for(int rem = 1; rem < k; rem++){
        for(int i = 0; i < m; i++){
          for(int j = 0; j < n; j++){
            for(int r = i + 1; r < m; r++){
              if(apples[i][j] > apples[r][j]){
                dp[rem][i][j] += dp[rem - 1][r][j];
                dp[rem][i][j] %= mod;
              }
            }
            for(int c = j + 1; c < n; c++){
              if(apples[i][j] > apples[i][c]){
                dp[rem][i][j] += dp[rem - 1][i][c];
                dp[rem][i][j] %= mod;
              }
            }
          }
        }
      }
      return dp[k - 1][0][0];
    }
};