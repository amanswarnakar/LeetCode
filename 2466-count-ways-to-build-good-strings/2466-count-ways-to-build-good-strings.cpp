class Solution {
public:
  int mod = 1e9+7;
  int f(int idx, int zero, int one, vector<int> &dp){
    if(dp[idx] != -1) return dp[idx];
    int cnt = 0;
    if(idx >= one) cnt += f(idx - one, zero, one, dp);
    if(idx >= zero) cnt += f(idx - zero, zero, one, dp);
    return dp[idx] = cnt % mod;
  }
  int countGoodStrings(int lo, int hi, int zero, int one) {
    vector<int> dp(hi + 1, -1);
    dp[0] = 1;
    int ans = 0;
    for(int i = lo; i <= hi; i++){
      ans += f(i, zero, one, dp);
      ans %= mod;
    }
    return ans;
  }
};