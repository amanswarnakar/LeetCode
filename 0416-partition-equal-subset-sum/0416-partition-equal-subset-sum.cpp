class Solution {
public:
    bool f(int idx, int t, vector<int> &v, vector<vector<int>> &dp){
      if(t == 0) return true;
      if(idx == 0) return v[0] == t;
      if(dp[idx][t] != -1) return dp[idx][t]; 
      bool notPick = f(idx - 1, t, v, dp);
      bool pick = false;
      if(v[idx] <= t) pick = f(idx - 1, t - v[idx], v, dp);
      return dp[idx][t] = pick or notPick;
    }
    bool canPartition(vector<int>& v) {
      int n = v.size(), sum = accumulate(v.begin(), v.end(), 0);
      if(sum & 1 == 1) return false;
      sum /= 2;
      vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
      return f(n - 1, sum, v, dp);
    }
};