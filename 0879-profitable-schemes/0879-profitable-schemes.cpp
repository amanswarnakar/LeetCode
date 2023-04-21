class Solution {
public:
    int mod = 1e9+7;
    int dp[101][101][101];
  
    int solve(int pos, int cnt, int profit, int n, int t, vector<int>& gr, vector<int>& pro){
      if(pos == gr.size()) return profit >= t;
      if(dp[pos][cnt][profit] != -1) return dp[pos][cnt][profit];
      int res = solve(pos + 1, cnt, profit, n, t, gr, pro);
      if(cnt + gr[pos] <= n){
        res += solve(pos + 1, cnt + gr[pos], min(t, profit + pro[pos]), n, t, gr, pro);
      }
      return dp[pos][cnt][profit] = res % mod;
    }
  
    int profitableSchemes(int n, int t, vector<int>& gr, vector<int>& pro) {
      memset(dp, -1, sizeof(dp));
      return solve(0, 0, 0, n, t, gr, pro);
    }
};