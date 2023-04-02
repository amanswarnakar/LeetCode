//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int knightInGeekland(int sx, int sy, vector<vector<int>> &arr){
        // Code here
        int m = arr.size(), n = arr[0].size();
        queue<pair<int, int>> q;
        q.emplace(sx, sy);
        vector<vector<bool>> vis(m, vector<bool>(n, false));
        vis[sx][sy] = true;
        vector<int> v, dx = {1, 2, 2, 1, -1, -2, -2, -1}, 
        dy = {2, 1, -1, -2, -2, -1, 1, 2};
        while(!q.empty()){
            int sz = q.size(), coins = 0;
            while(sz--){
                auto node = q.front(); q.pop();
                int r = node.first, c = node.second;
                coins += arr[r][c];
                for(int i = 0; i < 8; i++){
                    int x = r + dx[i], y = c + dy[i];
                    if(min(x, y) < 0 or x >= m or y >= n or vis[x][y]) continue;
                    vis[x][y] = true;
                    q.emplace(x, y);
                }
            }
            v.emplace_back(coins);
        }
        int ans, maxi = INT_MIN, sz = v.size();
        for(int i = sz - 1; i >= 0; i--){
            if(v[i] + i < sz){
                v[i] += v[v[i] + i];
            }
            if(v[i] >= maxi){
                maxi = v[i];
                ans = i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,start_x,start_y;
        cin>>n>>m>>start_x>>start_y;
        vector<vector<int>> arr(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
            }
        }
        Solution ob;
        cout<<ob.knightInGeekland(start_x,start_y,arr)<<endl;
    }
}
// } Driver Code Ends