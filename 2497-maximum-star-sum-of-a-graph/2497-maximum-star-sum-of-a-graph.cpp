class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
      if(edges.size() == 0) return *max_element(vals.begin(), vals.end());
      int n = vals.size(), ans = 0;
      vector<vector<int>> graph(n);
      for(auto &edge: edges){
        graph[edge[0]].emplace_back(edge[1]);
        graph[edge[1]].emplace_back(edge[0]);
      }
      for(int i = 0; i < n; i++){
        int temp = vals[i]; 
        priority_queue<int, vector<int>, greater<>> pq;
        for(auto &i: graph[i]){
          pq.push(vals[i]);
          if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()){
          if(pq.top() > 0) temp += pq.top();
          pq.pop();
        }
        ans = max(ans, temp);
      }
      return ans;
    }
};