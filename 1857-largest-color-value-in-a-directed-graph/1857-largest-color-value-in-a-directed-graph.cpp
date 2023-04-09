class Solution {
public:
    int largestPathValue(string s, vector<vector<int>>& edges) {
      int n = s.size();
      vector<vector<int>> graph(n);
      vector<int> indegree(n);
      for(auto &e: edges){
        graph[e[0]].emplace_back(e[1]);
        indegree[e[1]]++;
      }
      vector<vector<int>> count(n, vector<int>(26));
      queue<int> q;
      for (int i = 0; i < n; i++) {
        if (indegree[i] == 0) {
          q.emplace(i);
        }
      }
      int ans = 0, seen = 0;
      while(!q.empty()){
        int node = q.front(); q.pop();
        ans = max(ans, ++count[node][s[node] - 'a']);
        seen++;
        for(auto &adj: graph[node]){
          for(int i = 0; i < 26; i++){
            count[adj][i] = max(count[adj][i], count[node][i]);
          }
          indegree[adj]--;
          if(indegree[adj] == 0) q.emplace(adj);
        }
      }
      return seen < n ? -1 : ans;
    }
};