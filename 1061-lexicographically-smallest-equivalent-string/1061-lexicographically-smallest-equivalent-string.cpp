class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool> &vis, int &node, int &mini){
      vis[node] = true;
      mini = min(mini, node);
      for(auto &adj: graph[node]){
        if(!vis[adj]) dfs(graph, vis, adj, mini);
      }
    }
    string smallestEquivalentString(string s1, string s2, string t) {
      int n = s1.size();
      vector<vector<int>> graph(26);
      for(int i = 0; i < n; i++){
        graph[s1[i] - 'a'].emplace_back(s2[i] - 'a');
        graph[s2[i] - 'a'].emplace_back(s1[i] - 'a');
      }
      vector<int> mapping(26, 0);
      for(int i = 0; i < 26; i++){
        vector<bool> vis(26, false);
        int mini = 27;
        dfs(graph, vis, i, mini);
        mapping[i] = mini;
      }
      for(int i = 0; i < t.size(); i++){
        t[i] = mapping[t[i] - 'a'] + 'a';
      }
      return t;
    }
};