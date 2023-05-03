//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    bool makePalindrome(int n, vector<string> &v){
        // Code here
        unordered_map<string, int> um;
        for(auto &i: v) um[i]++;
        for(int i = 0; i < n; i++){
            string temp = v[i];
            reverse(temp.begin(), temp.end());
            if(um[temp] > 0) um[temp]--;
            else if(um[temp] == 0) um.erase(temp);
        }
        for(auto &i: um){
            if(i.second != 0) return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        if(ob.makePalindrome(n,arr)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
// } Driver Code Ends