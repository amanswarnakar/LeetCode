class Solution {
public:
    bool canPlaceFlowers(vector<int>& v, int k) {
      int n = v.size(), ans = 0;
      for(int i = 0; i < n; i++){
        if(v[i] == 0){
          bool left = (i == 0) or (v[i - 1] == 0);
          bool right = (i == n - 1) or (v[i + 1] == 0);
          if(left and right){
            v[i] = 1;
            ans++;
            if(ans >= k) return true;
          }
        }
      }
      return ans >= k;
    }
};