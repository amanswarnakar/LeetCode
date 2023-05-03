//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int f(int idx, int w, vector<pair<int, int>> &vp, vector<vector<int>> &dp){
        if(w < 0) return -1e8;
        if(idx == 0) return vp[idx].first <= w ? vp[idx].second : 0;
        if(dp[idx][w] != -1) return dp[idx][w];
        int pick = -1;
        if(vp[idx].first <= w) pick = vp[idx].second + f(idx - 1, w - vp[idx].first, vp, dp);
        int notPick = f(idx - 1, w, vp, dp);
        return dp[idx][w] = max(pick, notPick);
    }
    int knapSack(int w, int wt[], int val[], int n) 
    { 
       // Your code here
        vector<pair<int, int>> vp;
        vector<vector<int>> dp(n, vector<int>(w + 1, -1));
        for(int i = 0; i < n; i++){
            vp.emplace_back(make_pair(wt[i], val[i]));  
        }
        int ans = f(n - 1, w, vp, dp);
        // for(auto &i: dp){
        //     for(auto &j: i) cout<<j<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends