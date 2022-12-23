class Solution {
public:
    int helper(int i, int canBuy, vector<int> &v, vector<vector<int>> &dp){
      if(i >= v.size()) return 0;
      if(dp[i][canBuy] != -1) return dp[i][canBuy];
      if(canBuy)  return dp[i][canBuy] = max(-v[i] + helper(i + 1, 0, v, dp), 0 + helper(i + 1, 1, v, dp));
      else return dp[i][canBuy] = max(v[i] + helper(i + 2, 1, v, dp), 0 + helper(i + 1, 0, v, dp));
    }
  
    int maxProfit(vector<int>& v) {
      int n = v.size();
      vector<vector<int>> dp(n, vector<int>(2, -1));
      return helper(0, 1, v, dp);
    }
};