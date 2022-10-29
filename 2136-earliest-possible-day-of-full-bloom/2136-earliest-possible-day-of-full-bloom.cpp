class Solution {
public:
    int earliestFullBloom(vector<int>& p, vector<int>& g) {
      int n = p.size(), ans = 0, temp = 0;
      vector<vector<int>> v(n, vector<int>(2, 0));
      for(int i = 0; i < n; i++){
        v[i][0] = g[i];
        v[i][1] = p[i];
      }
      sort(begin(v), end(v), greater<>());
      for(int i = 0; i < n; i++){
        temp += v[i][1];
        ans = max(ans, temp + v[i][0]);
      }
      return ans;
    }
};