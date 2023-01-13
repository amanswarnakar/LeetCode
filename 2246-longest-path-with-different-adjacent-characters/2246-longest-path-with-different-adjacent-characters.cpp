class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
      int n = s.size(), ans = 0;
      vector<vector<int>> graph(n);
      for (int i = 1; i < n; ++i)
        graph[parent[i]].push_back(i);
      dfs(graph, s, ans, 0);
      return ans;
    }

    int dfs(vector<vector<int>>& graph, string& s, int& ans, int node) {
      int big1 = 0, big2 = 0;
      for (int& adj : graph[node]) {
        int cur = dfs(graph, s, ans, adj);
        if (s[node] == s[adj]) continue;
        if (cur > big2) big2 = cur;
        if (big2 > big1) swap(big1, big2);
      }
      ans = max(ans, big1 + big2 + 1);
      return big1 + 1;
    }
};