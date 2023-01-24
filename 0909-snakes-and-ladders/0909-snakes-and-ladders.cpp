class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& b) {
      int n = b.size();
      vector<pair<int, int>> g(n * n + 1);
      vector<int> traverse(n);
      iota(traverse.begin(), traverse.end(), 0);
      int node = 1;
      for(int i = n - 1; i >= 0; i--){
        for(auto &j: traverse){
          g[node++] = {i, j};
        }
        reverse(traverse.begin(), traverse.end());
      }
      vector<int> v(n * n + 1, -1);
      v[1] = 0;
      queue<int> q;
      q.emplace(1);
      while(!q.empty()){
        auto top = q.front(); q.pop();
        for(int i = top + 1; i <= min(top + 6, n * n); i++){
          auto [r, c] = g[i];
          int dest = b[r][c] == -1 ? i : b[r][c];
          if(v[dest] == -1){
            v[dest] = v[top] + 1;
            q.emplace(dest);
          }
        }
      }
      return v[n * n];
    }
};