class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
      int n = grid.size(), ans = 0;
      vector<int> mxy(n, -1), mxx(n, -1);
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          mxx[i] = max(mxx[i], grid[i][j]);
          mxy[i] = max(mxy[i], grid[j][i]);
        }
      }
      for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
          int diff = min(mxx[i], mxy[j]) - grid[i][j];
          ans += diff;
        }
      }
      return ans;
    }
};