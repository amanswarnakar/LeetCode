class Solution {
public:
//     void dfs(vector<vector<int>> &graph, vector<vector<int>> &back, vector<bool> &vis, int &ans, int cn){
//       for(auto &node : graph[cn]){
//         if(!vis[node]){
//           vis[node] = true;
//           ans++;
//           dfs(graph, back, vis, ans, node);
//         }
//       }
//       for(auto &node : back[cn]){
//         if(!vis[node]){
//           vis[node] = true;
//           dfs(graph, back, vis, ans, node);          
//         }
//       }
//     }
  
//     int minReorder(int n, vector<vector<int>>& connections) {
//       vector<bool> vis(n, false);
//       vis[0] = true;
//       vector<vector<int>> graph(n), back(n);
//       for(auto &con: connections){
//         graph[con[0]].emplace_back(con[1]);
//         back[con[1]].emplace_back(con[0]);
//       }
//       int ans = 0;
//       dfs(graph, back, vis, ans, 0);
//       return ans;
//     }
  
  
    int minReorder(int n, vector<vector<int>>& connections) {
      // BFS
      int ans = 0;
      vector<vector<int>> graph(n), back(n);
      vector<bool> vis(n);
      queue<int> q;
      q.emplace(0);

      for(auto &con : connections){
        graph[con[0]].emplace_back(con[1]);
        back[con[1]].emplace_back(con[0]);
      }

      while(!q.empty()){
        int curr = q.front();
        q.pop();
        vis[curr] = true;
        for(auto &node: graph[curr]){
          if(!vis[node]){
            ans++; q.emplace(node);
          }
        }
        for(auto &node: back[curr]){
          if(!vis[node]) q.emplace(node);
        }
      }
      return ans;
    }
  
    //  void dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<vector<int>> &outgoing, int cn, int parentNode, int &ans){
    //   vis[cn] = true;
    //   if(parentNode != -1){
    //     if(find(outgoing[cn].begin(), outgoing[cn].end(), parentNode) == outgoing[cn].end())
    //       ans++;
    //   }
    //   for(auto &node : graph[cn]){
    //     if(!vis[node])
    //       dfs(graph, vis, outgoing, node, cn, ans);
    //   }
    // }
    // int minReorder(int n, vector<vector<int>>& connections) {
    //   int ans = 0;
    //   vector<bool> vis(n, false);
    //   vector<vector<int>> graph(n);
    //   vector<vector<int>> outgoing(n);
    //   for(auto &con : connections){
    //     graph[con[0]].emplace_back(con[1]);
    //     graph[con[1]].emplace_back(con[0]);
    //     outgoing[con[0]].emplace_back(con[1]);
    //   }
    //   dfs(graph, vis, outgoing, 0, -1, ans);
    //   return ans;
    // } 
};