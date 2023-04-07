//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    bool isPalindrome(string &s, int l, int r){
        while(l < r) 
            if(s[l++] != s[r--]) return false;
        return true;
    }
    int addMinChar(string s){    
        //code here
        int n = s.size(), cnt = 0, ans = 0;
        for(int r = 1, l = 0; r < n; r++){
            if(isPalindrome(s, l, r)) cnt = r;
        }
        return n - cnt - 1;
    }
};

//{ Driver Code Starts.


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin >> str;
        
        Solution ob;
        cout << ob.addMinChar(str) << endl;
    }
    return 0; 
} 
// } Driver Code Ends