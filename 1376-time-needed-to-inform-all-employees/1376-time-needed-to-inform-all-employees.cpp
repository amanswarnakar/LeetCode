class Solution {
public:
    int dfs(vector<vector<int>> &graph, int curManager, vector<int> &time){
      int temp = 0;
      for(int u : graph[curManager]){
        temp = max(temp, dfs(graph, u, time));
      }
      return time[curManager] + temp;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& time) {
      // DFS
      
      vector<vector<int>> graph(n);
      for(int i = 0; i < n; i++){
        if(manager[i] != -1)
          graph[manager[i]].push_back(i);
      }
      return dfs(graph, headID, time);
    }
};