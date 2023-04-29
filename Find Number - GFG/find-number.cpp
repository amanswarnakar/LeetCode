//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    long long findNumber(long long n){
        // Code here
        long long ans = 0;
        vector<int> v;
        while(n){
            n--;
            v.emplace_back(n % 5);
            n /= 5;
        }
        for(int i = v.size() - 1; i >= 0; i--){
            ans = ans * 10 + 2 * v[i] + 1;
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        long long N;
        cin>>N;
        Solution ob;
        cout<<ob.findNumber(N)<<endl;
    }
    return 0;
}
// } Driver Code Ends