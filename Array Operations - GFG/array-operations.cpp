//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int arrayOperations(int n, vector<int> &v) {
        // code here
        int ans = 1;
        bool flag = false;
        for(int i = 0; i < n - 1; i++){
            if(v[i] == 0) flag = true;
            if(v[i] != 0 and v[i + 1] == 0){
                ans++; flag = true;
            }
        }
        if(!flag) return -1;
        if(v[n - 1] == 0) return ans - 1;
        return ans;  
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        Solution obj;
        int res = obj.arrayOperations(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends