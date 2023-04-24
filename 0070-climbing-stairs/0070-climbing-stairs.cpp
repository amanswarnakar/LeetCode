class Solution {
public:
    int climbStairs(int n) {
      int p1 = 1, p2 = 0;
      for(int i = 0; i < n; i++){
        int curr = p1 + p2;
        p2 = p1;
        p1 = curr;
      }
      return p1;
    }
  
  /*
    int solve(int n){
      if(n == 0) return 1;
      if(n < 0) return 0;
      return solve(n - 1) + solve(n - 2);
    }
    int climbStairs(int n) {
      return solve(n);
    }
  */
};