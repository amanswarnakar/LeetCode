// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n)
    {   
        vector<int> preSum(n+1, 0);
        preSum[1] = arr[0];
        for(int i = 1; i < n; i++){
            preSum[i+1] = preSum[i] + arr[i];
        }
        map<int, vector<int>> mp;
        // mp[0].push_back(0);
        for(int i = 0; i < n+1; i++){
            mp[preSum[i]].push_back(i);
        }
        int ans = 0;
        for(auto i = mp.begin(); i != mp.end(); i++){
            ans = max(ans, i->second.back() - i->second.front());
        }
        return ans;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends