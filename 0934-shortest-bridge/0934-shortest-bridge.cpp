class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    void dfsMarkIslandVisited(vector<vector<int>> &v, vector<vector<int>> &vis, queue<pair<pair<int, int>, int>> &q, int r, int c){
      if(r < 0 or r >= v.size() or c < 0 or c >= v[0].size() or vis[r][c] or v[r][c] == 0) return;
      vis[r][c] = 1;
      q.push({{r, c}, 0});
      for(int i = 0; i < 4; i++){
        dfsMarkIslandVisited(v, vis, q, r + dx[i], c + dy[i]);
      }
    }
  
    int shortestBridge(vector<vector<int>>& v) {
      int m = v.size(), n = v[0].size(), ans = INT_MAX;
      vector<vector<int>> vis(m, vector<int>(n, 0));
      bool flag = false;
      queue<pair<pair<int, int>, int>> q;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j] and vis[i][j] == 0){
            q.push({{i, j}, 0});
            dfsMarkIslandVisited(v, vis, q, i, j);
            flag = true;
          }
          if(flag) break;
        }
        if(flag) break;
      }
      while(!q.empty()){
        int r = q.front().first.first, c = q.front().first.second;
        ans = q.front().second;
        // cout<<r<<" "<<c<<" "<<ans<<endl;
        q.pop();
        for(int i = 0; i < 4; i++){
          int x = r + dx[i], y = c + dy[i];
          if(x >= 0 and x < m and y >= 0 and y < n and vis[x][y] == 0){
            if(v[x][y] == 1) return ans;
            q.push({{x, y}, ans + 1});
            vis[x][y] = 1;
          }
        }
      }
      // for(auto i : vis){
      //   for(auto j : i)
      //     cout<<j<<" ";
      //   cout<<endl;
      // }
      return ans;
    }
};