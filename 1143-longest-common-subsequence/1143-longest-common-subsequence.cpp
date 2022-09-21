class Solution {
public:
    int longestCommonSubsequence(string t1, string t2) {
      int n = t1.size(), m = t2.size();
      vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
      for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
          if(t1[i] == t2[j]){
            dp[i+1][j+1] = dp[i][j] + 1;
          } else {
            dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
          }
        }
      }
      // for(auto i : dp){
      //   for(auto j : i){
      //     cout<<j<<" ";
      //   } cout<<endl;
      // } cout<<endl;
      return dp[n][m];
    }
};