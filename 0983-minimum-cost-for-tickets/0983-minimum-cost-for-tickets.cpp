class Solution {
public:
    int recur(int idx, int n, vector<int> &v, vector<int> &cost, vector<int> &dp){
      if(idx >= n){
        return 0; 
      }
      if(dp[idx] != -1) return dp[idx];
      int op1 = cost[0] + recur(idx + 1, n, v, cost, dp);
      
      int i;
      for(i = idx; i < n and v[i] < v[idx] + 7; i++);
      int op2 = cost[1] + recur(i, n, v, cost, dp);
      
      for(i = idx; i < n and v[i] < v[idx] + 30; i++);
      int op3 = cost[2] + recur(i, n, v, cost, dp);
      
      return dp[idx] = min(op1, min(op2, op3));
    }
    int mincostTickets(vector<int>& v, vector<int>& cost) {
      int n = v.size();
      vector<int> dp(n + 1, -1);
      return recur(0, n, v, cost, dp);
      // return dp[0];
    }
};