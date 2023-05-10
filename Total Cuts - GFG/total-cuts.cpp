//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int totalCuts(int n, int k, vector<int> &v){
        // Code here
        vector<int> v1(n), v2(n);
        int temp = 0, ans = 0;
        for(int i = 0; i < n; i++){
            temp = max(temp, v[i]);
            v1[i] = temp;
        }
        temp = INT_MAX;
        for(int i = n - 1; i >= 0; i--){
            temp = min(temp, v[i]);
            v2[i] = temp;
        }
        for(int i = 0; i < n - 1; i++){
            if(v1[i] + v2[i + 1] >= k) ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N,K;
        cin>>N>>K;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        Solution ob;
        cout<<ob.totalCuts(N,K,A)<<endl;
    }
    return 0;
}
// } Driver Code Ends