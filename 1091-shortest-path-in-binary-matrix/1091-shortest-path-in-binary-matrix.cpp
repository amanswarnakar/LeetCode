class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size();
      if(m == 0 || n == 0 || v[0][0] == 1 || v[m-1][n-1] == 1) return -1;
      int ans = 1;
      queue<pair<int, int>> q;
      q.push({0,0});
      v[0][0] = 1;
      int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
      int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};
      while(!q.empty()){
        auto temp = q.front();
        int x = temp.first, y = temp.second;
        if(x == m - 1 and y == n - 1) return v[x][y];
        for(int i = 0; i < 8; i++){
          int xx = x + dx[i], yy = y + dy[i];
          if(xx >= 0 and xx <= m - 1 and yy >= 0 and yy <= n-1 and v[xx][yy] == 0){
            q.push({xx, yy});
            v[xx][yy] = v[x][y] + 1;
          }
        }
        q.pop();
      }
      return -1;
    }
};