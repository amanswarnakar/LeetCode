class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& v, int r, int c) {
      vector<vector<int>> ans(r, vector<int>(c));
      int m = v.size(), n = v[0].size();
      if(m * n < r * c or m * n > r * c) return v;
      for(int i = 0; i < m * n; i++){
        ans[i / c][i % c] = v[i / n][i % n];
      }
      return ans;
    }
};