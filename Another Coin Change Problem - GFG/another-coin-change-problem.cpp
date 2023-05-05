//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool f(int idx, int k, int t, vector<int> &v, vector<vector<vector<int>>> &dp){
        if(t == 0) return k == 0;
        if(k == 0) return false;
        if(idx == 0) return (t % v[0] == 0) and (t / v[0] == k);
        if(dp[idx][k][t] != -1) return dp[idx][k][t];
        bool pick = false;
        if(v[idx] <= t) pick = f(idx, k - 1, t - v[idx], v, dp);
        bool notPick = f(idx - 1, k, t, v, dp);
        return dp[idx][k][t] = pick or notPick;
    }
    bool makeChanges(int n, int k, int t, vector<int> &v) {
        // code here
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(k + 1, vector<int>(t + 1, -1)));
        return f(n - 1, k, t, v, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends