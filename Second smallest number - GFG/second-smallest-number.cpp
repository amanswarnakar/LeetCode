//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        // code here
        if(s == 1 or d == 1 or s >= 9 * d) return "-1";
        string ans(d, '0');
        int sum = s, last = -1;
        
        for(int i = d - 1; i >= 0; i--){
            if(sum > 9){
                ans[i] = '9';
                sum -= 9;
            } else if(sum > 0){
                ans[i] = '0' + sum;
                sum = 0;
                last = i;
            } else continue;
        }
        if(ans[0] == '0'){
            ans[0]++;
            ans[last]--;
        }
        last = d - 2;
        while(ans[last] == '9') last--;
        ans[last]++;
        ans[last + 1]--;
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends