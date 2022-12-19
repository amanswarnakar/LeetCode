class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int s, int t) {
      vector<vector<int>> graph(n);
      vector<bool> vis(n);
      for(auto &e: edges){
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
      }
      queue<int> q;
      q.emplace(s);
      while(!q.empty()){
        int sz = q.size();
        for(int i = 0; i < sz; i++){
          int node = q.front(); q.pop();
          vis[node] = true;
          if(node == t) return true;
          for(auto &adj: graph[node]){
            if(!vis[adj]){
              q.emplace(adj);
              vis[adj] = true;
            }
          }
        }
      }
      return false;
    }
};