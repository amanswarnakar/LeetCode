//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int helper(string s, int idx){
        int res = 0, cnt = 0;
        for(int i = idx; i < s.size(); i++){
            if(islower(s[i])) cnt--;
            else cnt++;
            if(i != idx and !cnt) res++;
        }
        return res;
    }
    int countSubstring(string s){
        // code here
        int n = s.size(), ans = 0;
        for(int i = 0; i < n; i++){
            ans += helper(s, i);
        }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends