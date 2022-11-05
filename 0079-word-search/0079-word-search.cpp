class Solution {
public:
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}; 
    bool dfs(vector<vector<char>> &v, string word, int r, int c, int step = 0){
      if(!word.size()) return true;
      if(min(r, c) < 0 or r >= v.size() or c >= v[0].size()) return false;
      if(v[r][c] != word[0]) return false;
      char ch = v[r][c];
      v[r][c] = '*';
      word = word.substr(1);
      bool up = dfs(v, word, r, c - 1, step+1);
      bool down = dfs(v, word, r, c + 1, step+1);
      bool right = dfs(v, word, r + 1, c, step+1);
      bool left = dfs(v, word, r - 1, c, step+1);
      v[r][c] = ch;
      return up or down or left or right;
    }
    bool exist(vector<vector<char>>& v, string word) {
      int m = v.size(), n = v[0].size(), w = word.size();
      queue<pair<int, int>> q;
      for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
          if(v[i][j] == word[0])
            if(dfs(v, word, i, j)) return true;
        }
      }
      return false;
//       int step = 1, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
//       while(q.size()){
//         for(auto i = 0; i < q.size(); i++){
//           auto top = q.front(); q.pop();
//           int r = top.first, c = top.second;
//           cout<<"r "<<r<<" c "<<c<<" "<<v[r][c]<<" "<<word[step]<<endl;
          
//           if(word[w - 1] == v[r][c] and step == w - 1)
//             return true;
//           for(int j = 0; j < 4; j++){
//             int x = r + dx[j], y = c + dy[j];
//             if(min(x, y) >= 0 and x < m and y < n){
//               if(v[x][y] == word[step]){
//                 q.emplace(x, y);
//               }
//             }
//           }          
//         }
//         step++;
//       }
//      return false;
    }
};