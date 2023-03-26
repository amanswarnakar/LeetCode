class Solution {
public:
    int ans = -1;
    void dfs(int node, vector<int>& edges, unordered_map<int, int> &dist, vector<bool>& vis) {
        vis[node] = true;
        int adj = edges[node];
        if (adj != -1 && !vis[adj]) {
            dist[adj] = dist[node] + 1;
            dfs(adj, edges, dist, vis);
        } else if (adj != -1 && dist.count(adj)) {
            ans = max(ans, dist[node] - dist[adj] + 1);
        }
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> vis(n);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                unordered_map<int, int> dist;
                dist[i] = 1;
                dfs(i, edges, dist, vis);
            }
        }
        return ans;
    }
};