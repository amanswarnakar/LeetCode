class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> vis(n, 0);
      queue<vector<int>> q;
      for(int i = 0; i < n; i++){
        if(!vis[i]){
          q.push({i, 1});
          while(!q.empty()){
            auto top = q.front(); q.pop();
            int cn = top[0], color = top[1];
            vis[cn] = color;
            for(auto &node: graph[cn]){ 
              if(!vis[node]){
                if(color == 1)  q.push({node, -1});
                else if(color == -1) q.push({node, 1});
              } else {
                if(color == vis[node])
                  return false;
              }
            }
          }
        }
      }
      return true;
    }
};