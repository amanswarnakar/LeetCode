class Solution {
public:
    int change(int tar, vector<int>& v) {
      int n = v.size();
      // vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
      vector<int> prev(tar + 1, 0), curr(tar + 1, 0);
      for(int t = 0; t < tar + 1; t++){
        prev[t] = (t % v[0] == 0);
      }
      for(int i = 1; i < n; i++){
        for(int t = 0; t < tar + 1; t++){
          int pick = 0;
          if(v[i] <= t) pick = curr[t - v[i]];
          int notPick = prev[t];
          curr[t] = pick + notPick;
        }
        prev = curr;
      }
      return prev[tar];
    }
  
    /*
    int change(int tar, vector<int>& v) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
      for(int t = 0; t < tar + 1; t++){
        dp[0][t] = (t % v[0] == 0);
      }
      for(int i = 1; i < n; i++){
        for(int t = 0; t < tar + 1; t++){
          int pick = 0;
          if(v[i] <= t) pick = dp[i][t - v[i]];
          int notPick = dp[i - 1][t];
          dp[i][t] = pick + notPick;
        }
      }
      return dp[n - 1][tar];
    }
    */
  
  
    /*
    int f(int idx, int t, vector<int> &v, vector<vector<int>> &dp){
      if(idx == 0) return (t % v[0] == 0);
      if(dp[idx][t] != -1) return dp[idx][t];
      int pick = 0;
      if(v[idx] <= t) pick = f(idx, t - v[idx], v, dp);
      int notPick = f(idx - 1, t, v, dp);
      return dp[idx][t] = pick + notPick;
    }
    int change(int tar, vector<int>& v) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
      return f(n - 1, tar, v, dp);
    }
    */
};