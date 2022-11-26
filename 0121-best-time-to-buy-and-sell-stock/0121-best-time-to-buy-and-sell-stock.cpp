class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // int x = prices[0], ans = 0;
      // for(int i = 1; i < prices.size(); i++){
      //   x = min(x, prices[i]);
      //   int diff;
      //   if(prices[i] - x <= 0)
      //     diff = 0;
      //   else  diff = prices[i] - x;
      //   ans = max(ans, diff);
      // }
      // return ans;
      
      
      // OPTIMIZED SOLUTION
      
      int n = prices.size();
      int l = 0, r = 1, ans = 0;
      if(n == 1) return 0;
      while(r < n){
        if(prices[r] > prices[l])
          ans = max(ans, prices[r] - prices[l]);
        else l = r;
        r++;
      }
      return ans;
    }
};