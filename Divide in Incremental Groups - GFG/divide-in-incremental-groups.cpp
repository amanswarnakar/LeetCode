//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countWaystoDivide(int n, int k) {
        // Code here
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for(int i = 0; i < n + 1; i++) dp[i][1] = 1;
        for(int i = 1; i < n + 1; i++){
            for(int j = 0; j < k + 1; j++){
                if(i >= j) dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
            }
        }
        return dp[n][k];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends