class Solution {
public:
    int recur(int i, int j, string &s, vector<vector<int>> &dp){
      if(i > j) return 0;
      if(i == j) return 1;
      if(dp[i][j] != -1) return dp[i][j];
      int ans = 0;
      if(s[i] == s[j]) ans = 2 + recur(i + 1, j - 1, s, dp);
      else ans = max(recur(i + 1, j, s, dp), recur(i, j - 1, s, dp));
      return dp[i][j] = ans;
    }
    int longestPalindromeSubseq(string s) {
      int n = s.size();
      vector dp(n, vector<int>(n, -1));
      return recur(0, n - 1, s, dp);
    }
};