//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int recur(int i, int t, int coins[], vector<vector<int>> &dp){
	    if(i == 0){
	        if(t % coins[i] == 0) return t / coins[i];
	        return 1e9;
	    }
	    if(dp[i][t] != -1) return dp[i][t];
	    int notPick = 0 + recur(i - 1, t, coins, dp);
	    int pick = 1e9;
	    if(coins[i] <= t) pick = 1 + recur(i, t - coins[i], coins, dp);
	
	    return dp[i][t] = min(pick, notPick);
	}
	
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	    vector<vector<int>> dp(M, vector<int> (V + 1, -1));
	    int ans = recur(M - 1, V, coins, dp);
	    return ans >= 1e9 ? -1 : ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends