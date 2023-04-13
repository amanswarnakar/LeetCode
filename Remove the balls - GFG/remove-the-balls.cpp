//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> color, vector<int> radius) {
        stack<pair<int, int>> spi;
        for(int i = 0; i < n; i++){
            if(spi.empty()) spi.push({color[i], radius[i]});
            else if(spi.top().first == color[i] and spi.top().second == radius[i]){
                spi.pop();
            } else spi.push({color[i], radius[i]});
        }
        return spi.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends