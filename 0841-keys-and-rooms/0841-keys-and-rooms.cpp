class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int currNode){
      if(vis[currNode]) return;
      vis[currNode] = true;
      for(int node: graph[currNode]){
        dfs(graph, vis, node);
      }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
      int n = rooms.size();
      vector<bool> vis(n, false);
      dfs(rooms, vis, 0);
      return accumulate(vis.begin(), vis.end(), 0) == n;
    }
};