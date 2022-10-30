class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& r, vector<vector<int>>& b) {
      vector<vector<pair<int, int>>> graph(n);
      // red edges are marked as 0, blue edges as 1
      for(auto &edge : r)
        graph[edge[0]].emplace_back(edge[1], 0);
      for(auto &edge : b)
        graph[edge[0]].emplace_back(edge[1], 1);
      vector<int> ans(n, -1);
      queue<vector<int>> q;   // queue will store node, distance, color
      q.emplace(vector<int>{0, 0, -1});  // color is -1 for node 0 only
      while(!q.empty()){
        auto front = q.front();
        int currNode = front[0], dist = front[1], color = front[2];
        cout<<currNode<<" "<<dist<<" "<<color<<endl;
        q.pop();
        if(ans[currNode] == -1)  ans[currNode] = dist;
        for(auto &node : graph[currNode]){
          if(node.first != -1 and node.second != color){
            q.emplace(vector<int>{node.first, dist + 1, node.second});
            node.first = -1;
          }
        }
      }
      return ans;
    }
};