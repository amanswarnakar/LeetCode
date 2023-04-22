class Solution {
public:
    int solve(string &s, string &rev, int m, int n, vector<vector<int>> &dp){
      if(m == 0 or n == 0) return 0;
      if(dp[m][n] != -1) return dp[m][n];
      if(s[m - 1] == rev[n - 1]) return dp[m][n] = 1 + solve(s, rev, m - 1, n - 1, dp);
      return dp[m][n] = max(solve(s, rev, m - 1, n, dp), solve(s, rev, m, n - 1, dp));
    }
    int minInsertions(string s) {
      int n = s.size();
      string rev = s;
      reverse(s.begin(), s.end());
      vector dp(n + 1, vector<int>(n + 1, -1));
      return n - solve(s, rev, n, n, dp);
    }
};