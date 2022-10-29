class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
      vector<vector<int>> graph(n, vector<int>(n, 0));
      vector<int> degree(n);
      int ans = INT_MIN;
      for(auto road: roads){
        graph[road[0]][road[1]] = 1;
        graph[road[1]][road[0]] = 1;
        degree[road[0]]++;
        degree[road[1]]++;
      }
      for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
          int temp = degree[i] + degree[j];
          if(graph[i][j]) temp--;
          ans = max(ans, temp);
        }
      }
      return ans;
    }
};