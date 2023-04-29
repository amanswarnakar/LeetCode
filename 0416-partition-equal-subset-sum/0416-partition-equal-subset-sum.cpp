class Solution {
public:
    // Tabulation
  
    bool canPartition(vector<int>& v) {
      int n = v.size(), sum = accumulate(v.begin(), v.end(), 0);
      if((sum & 1) == 1) return false;
      sum /= 2;
      vector<vector<bool>> dp(n, vector<bool>(sum + 1, 0));
      if(v[0] <= sum) dp[0][v[0]] = true;
      
      for(int i = 0; i < n; i++) dp[i][0] = true;
      
      for(int i = 1; i < n; i++){
        for(int j = 1; j < sum + 1; j++){
          bool notPick = dp[i - 1][j];
          bool pick = false;
          if(v[i] <= j) pick = dp[i - 1][j - v[i]];
          dp[i][j] = pick or notPick;
        }
      }
      return dp[n - 1][sum];
    }
  
    /*
    // Memoization
    
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
    */
};