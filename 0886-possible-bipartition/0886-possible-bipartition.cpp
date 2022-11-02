class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& v) {
      // int n = v.size();
      vector<vector<int>> graph(n);
      for(auto edge: v){
        graph[edge[0] - 1].emplace_back(edge[1] - 1);
        graph[edge[1] - 1].emplace_back(edge[0] - 1);
      }
      vector<int> vis(n, 0);
      queue<int> q;
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          q.emplace(i);
          while(!q.empty()){
            int cn = q.front(); q.pop();
            vis[i] = 1;
            for(auto &node: graph[cn]){
              if(!vis[node]){
                q.emplace(node); vis[node] = - vis[cn];
              } else {
                if(vis[node] == vis[cn]) return false;
              }
            }
          }
        }
      }
      return true;
    }
};