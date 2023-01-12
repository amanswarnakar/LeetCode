class Solution {
    vector<int> ans;
public:
    vector<int> dfs(vector<vector<int>> &graph, int prev, int node, string &labels){
      vector<int> res(26, 0);
      for(auto &adj: graph[node]){
        if(prev != adj){
          vector<int> temp = dfs(graph, node, adj, labels);
          for(int i = 0; i < 26; i++)
            res[i] += temp[i];
        }
      }
      ans[node] = ++res[labels[node] - 'a'];
      return res;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
      ans.resize(n);
      vector<vector<int>> graph(n);
      for(auto &e: edges){
        graph[e[0]].emplace_back(e[1]);
        graph[e[1]].emplace_back(e[0]);
      }
      dfs(graph, -1, 0, labels);
      return ans;
    }
};