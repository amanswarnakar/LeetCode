class Solution {
public:
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
  
    bool isBorder(int m, int n, int r, int c){
      return (r == 0 or r == m - 1 or c == 0 or c == n - 1);
    }
  
    bool isValid(int m, int n, int r, int c){
      return (r >= 0 and r < m and c >= 0 and c < n);
    }
  
    int nearestExit(vector<vector<char>>& v, vector<int>& ent) {
      int m = v.size(), n = v[0].size(), sr = ent[0], sc = ent[1];
      int ans = 0;
      if(isBorder(m, n, sr, sc)) v[sr][sc] = '+';
      queue<pair<pair<int, int>, int>> q;
      q.push({{sr, sc}, 0});
      
      while(!q.empty()){
        int r = q.front().first.first, c = q.front().first.second;
        ans = q.front().second;
        q.pop();
        if(isBorder(m, n, r, c) and v[r][c] != '+') return ans;
        for(int i = 0; i < 4; i++){
          int x = r + dx[i], y = c + dy[i];
          if(isValid(m, n, x, y) and v[x][y] == '.'){
            q.push({{x, y}, ans + 1});
            v[x][y] = '*';
          }
        }
      }
      return -1;
      
      
//       int m = v.size(), n = v[0].size(), sr = ent[0], sc = ent[1];
//       int ans = 0;
//       if(isBorder(m, n, sr, sc)) v[sr][sc] = '+';
//       queue<pair<int, int>> q;
//       q.push({sr, sc});
      
//       while(!q.empty()){
//         int s = q.size();
//         for(int i = 0; i < s; i++){
//           int r = q.front().first, c = q.front().second;
//           q.pop();
//           if(isBorder(m, n, r, c) and v[r][c] != '+') return ans;
//           for(int i = 0; i < 4; i++){
//             int x = r + dx[i], y = c + dy[i];
//             if(isValid(m, n, x, y) and v[x][y] == '.'){
//               q.push({x, y});
//               v[x][y] = '*';
//             }
//           }
//         }
//         ans++;
//       }
//       return -1;
    }
};