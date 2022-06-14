class Solution {
public:
    // int lcs(string w1, string w2, int m, int n, vector<vector<int>> dp){
    //   if(m == 0 or n == 0) return 0;
    //   if(dp[m][n] != -1) return dp[m][n];
    //   if(w1[m-1] == w2[n-1]){
    //     return dp[m][n] = 1 + lcs(w1, w2, m-1, n-1, dp);
    //   } else {
    //     return dp[m][n] = max(lcs(w1, w2, m-1, n, dp), lcs(w1, w2, m, n-1, dp));
    //   }
    // }
  
    int minDistance(string word1, string word2) {
      int m = word1.length(), n = word2.length();
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      // int x =  lcs(word1, word2, m, n, dp);
      // return m + n - 2 * x;
      
      for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
          if(word1[i-1] == word2[j-1]){
            dp[i][j] = 1 + dp[i-1][j-1];
          } else {
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }
      return m + n - (2 * dp[m][n]);
    }
};