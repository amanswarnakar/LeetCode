class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int n = 0;
  
    void dfs(vector<vector<int>> &graph, int cur){
      temp.push_back(cur);
      if(cur == n) ans.push_back(temp);
      else {
        for(int node : graph[cur]){
          dfs(graph, node);
        }
      }
      temp.pop_back();
    }
  
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      n = graph.size() - 1;
      dfs(graph, 0);
      return ans;
    }
};