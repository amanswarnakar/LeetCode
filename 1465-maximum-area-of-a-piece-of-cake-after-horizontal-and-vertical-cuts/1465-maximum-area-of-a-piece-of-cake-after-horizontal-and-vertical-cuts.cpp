class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
      int n = hc.size(), m = vc.size();
      sort(hc.begin(), hc.end());
      sort(vc.begin(), vc.end());
      int x = max(hc[0], h - hc[n-1]);
      int y = max(vc[0], w - vc[m-1]);
      for(int i = 0; i < n-1; i++){
        int diff = hc[i+1] - hc[i];
        x = max(x, diff);
      }
      for(int i = 0; i < m-1; i++){
        y = max(y, vc[i+1] - vc[i]);
      }
      return int(((long long)x * (long long)y) % (1000000007ll));
    }
};