class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
      // Two Pointers - Sliding Window
      
      int l = 0, r = 0, n = v.size(), ans = INT_MAX, sum = 0;
      while(r < n){
        sum += v[r];
        while(sum >= t){
          ans = min(ans, r - l + 1);
          sum -= v[l++];
        }
        r++;
      }
      return (ans != INT_MAX) ? ans : 0;
    }
};