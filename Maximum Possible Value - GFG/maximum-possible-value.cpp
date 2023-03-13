//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    long long maxPossibleValue(int n, vector<int> a, vector<int> b) {
        // code here
        long long ans = 0, cnt = 0;
        int mini = INT_MAX;
        for(int i = 0; i < n; i++){
            if(b[i] > 1){
                cnt += b[i] / 2;
                ans += 2 * a[i] * (b[i] / 2);
                mini = min(mini, a[i]);
            }
        }
        if(cnt % 2){
            ans -= mini * 2;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends