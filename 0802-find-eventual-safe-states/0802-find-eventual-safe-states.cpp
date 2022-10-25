class Solution {
public:
    bool dfs(vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathVis, vector<bool> &isSafeNode, int currNode){
      vis[currNode] = true;
      pathVis[currNode] = true;
      isSafeNode[currNode] = false;
      for(auto node : graph[currNode]){
        if(!vis[node]){
          if(dfs(graph, vis, pathVis, isSafeNode, node)){
            isSafeNode[node] = false;
            return true;
          } 
        } else if(pathVis[node]) {
          isSafeNode[node] = false;
          return true;
        }
      }
      isSafeNode[currNode] = true;
      pathVis[currNode] = false;
      return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n = graph.size();
      vector<int> ans;
      vector<bool> vis(n, false), pathVis(n, false), isSafeNode(n, false);
      for(int i = 0; i < n; i++){
        if(!vis[i])
          dfs(graph, vis, pathVis, isSafeNode, i);
      }
      for(int i = 0; i < n; i++){
        if(isSafeNode[i]) ans.push_back(i);
      }
      return ans;
    }
};