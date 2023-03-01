//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    char s[4] = {'D', 'R', 'U', 'L'};
    void dfs(int r, int c, vector<vector<int>> &v, int n, string temp, 
                        vector<string> &ans, vector<vector<bool>> &vis) {
        if(v[r][c] != 1 or vis[r][c]) return;
        if(r == n - 1 and c == n - 1){
            ans.emplace_back(temp);
            return;
        }
        vis[r][c] = true;
        for(int i = 0; i < 4; i++){
            int x = r + dx[i], y = c + dy[i];
            if(min(x, y) >= 0 and max(x, y) < n and v[x][y] and !vis[x][y]){
                temp += s[i];
                dfs(x, y, v, n, temp, ans, vis);
                temp.pop_back();
            }
        }
        vis[r][c] = false;
        
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &v, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        string temp = "";
        dfs(0, 0, v, n, temp, ans, vis);
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends