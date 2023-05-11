class Solution {
public:
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
      int n1 = v1.size(), n2 = v2.size();
      vector<int> prev(n2 + 1, 0), curr(n2 + 1, 0);
      for(int i = 1; i < n1 + 1; i++){
        for(int j = 1; j < n2 + 1; j++){
          if(v1[i - 1] == v2[j - 1]) curr[j]  = 1 + prev[j - 1];
          else curr[j] = max(curr[j - 1], prev[j]);
        }
        prev = curr;
      }
      return prev[n2];
    }
  
  /*
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
      int n1 = v1.size(), n2 = v2.size();
      vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
      for(int i = 1; i < n1 + 1; i++){
        for(int j = 1; j < n2 + 1; j++){
          if(v1[i - 1] == v2[j - 1]) dp[i][j]  = 1 + dp[i - 1][j - 1];
          else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
        }
      }
      return dp[n1][n2];
    }
  */
  
  /*
    int f(int i1, int i2, vector<int> &v1, vector<int> &v2, vector<vector<int>> &dp){
      if(i1 <= 0 or i2 <= 0) return 0;
      if(dp[i1][i2] != -1) return dp[i1][i2];
      int equal = 0, unequal = 0;
      if(v1[i1 - 1] == v2[i2 - 1])
        equal = 1 + f(i1 - 1, i2 - 1, v1, v2, dp);
      else
        unequal = max(f(i1 - 1, i2, v1, v2, dp), f(i1, i2 - 1, v1, v2, dp));
      return dp[i1][i2] = max(equal, unequal);
    }
    int maxUncrossedLines(vector<int>& v1, vector<int>& v2) {
      int n1 = v1.size(), n2 = v2.size();
      vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));
      return f(n1, n2, v1, v2, dp);
    }
  */
};