//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string s){
        // Code here
        int n = s.size();
        string ans = "";
        ans += s[0];
        for(int i = 1; i < n; i++){
            if(s[i] <= s[i-1] and s[i] < s[0]) ans += s[i];
            else break;
        }
        n = ans.size();
        for(int i = n - 1; i >= 0; i--){
            ans += ans[i];
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends