//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> um;
        int mn = INT_MAX;
        for(int i = 0; i < n; i++){
            um[arr[i]]++;
        } 
        for(auto i: um){
            mn = min(mn, i.second);
        }
        int res = INT_MIN;
        for(auto i: um){
            if(i.second == mn) res = max(i.first, res);
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends