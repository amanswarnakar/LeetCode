//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool isSafe(int node, vector<int> &colors, int n, bool graph[101][101], int color){
        for(int i = 0; i < n; i++){
            if(graph[node][i] and colors[i] == color and i != node) return false;
        }
        return true;
    }
    bool solve(int node, vector<int> &colors, int m, int n, bool graph[101][101]){
        if(node == n) return true;
        for(int i = 1; i < m + 1; i++){
            if(isSafe(node, colors, n, graph, i)){
                colors[node] = i;
                if(solve(node + 1, colors, m, n, graph)) return true; 
                colors[node] = 0;
            }
        }
        return false;
    }
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> colors(n, 0);
        if(solve(0, colors, m, n, graph)) return true;
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends