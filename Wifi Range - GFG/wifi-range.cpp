//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        for(int i = 0; i < n; i++){
            if(s[i] == '1'){
                for(int j = 1; j <= x; j++){
                    if(i + j < n and s[i + j] == '0')
                        s[i + j] = '2';
                    if(i - j >= 0 and s[i - j] == '0')
                        s[i - j] = '2';
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] == '0') return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends