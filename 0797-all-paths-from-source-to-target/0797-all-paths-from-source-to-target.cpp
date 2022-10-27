class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<vector<int>> &ans, vector<int> &temp, int currNode, int n){
      temp.emplace_back(currNode);
      if(currNode == n) ans.emplace_back(temp);
      else for(auto &node: graph[currNode]){
        dfs(graph, ans, temp, node, n);
      }
      temp.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
      int n = graph.size() - 1;
      vector<int> temp;
      vector<vector<int>> ans;
      dfs(graph, ans, temp, 0, n);
      return ans;
    }
};