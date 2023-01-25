class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
      map<int, int> mp;
      int curr = node1, dist = 0, ans = INT_MAX, n = edges.size();
      vector<bool> vis(n, false);
      while(curr != -1 and vis[curr] == false){
        mp[curr] = dist++;
        vis[curr] = true;
        curr = edges[curr];
      }
      vis.assign(n, false);
      curr = node2;
      dist = 0;
      int node;
      while(curr != -1 and vis[curr] == false){
        if(mp.find(curr) != mp.end()){
          if(ans > max(mp[curr], dist)){
            ans = max(mp[curr], dist);
            node = curr;
          } 
          if(ans == max(mp[curr], dist)){
            node = min(node, curr);
          }
        }
        vis[curr] = true;
        dist++;
        curr = edges[curr];
      }
      return ans == INT_MAX ? -1 : node;
    }
};