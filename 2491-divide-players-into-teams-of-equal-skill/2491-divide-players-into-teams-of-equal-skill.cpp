class Solution {
public:
    long long dividePlayers(vector<int>& v) {
      int n = v.size(), l = 0, r = n - 1;
      sort(v.begin(), v.end());
      while(l < r){
        if(v[r - 1] - v[l] != v[r] - v[l + 1]) return -1;
        l++; r--;
      }
      l = 0; r = n - 1;
      long long int ans = 0;
      while(l < r) ans += v[l++] * v[r--];
      return ans;
    }
};