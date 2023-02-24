//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
    bool detect(vector<int> adj[], int src, vector<bool> &vis){
        queue<pair<int, int>> q;
        q.emplace(make_pair(src, -1));
        vis[src] = true;
        while(!q.empty()){
            int sz = q.size();
            for(int i = 0; i < sz; i++){
                auto top = q.front(); q.pop();
                int node = top.first, prev = top.second;
                for(auto &i: adj[node]){
                    if(i != prev){
                        if(vis[i]) return true;
                        vis[i] = true;
                        q.emplace(make_pair(i, node));
                    }
                }
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<bool> vis(n, false);
        for(int i = 0; i < n; i++){
            if(!vis[i] and detect(adj, i, vis)) return true;
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends