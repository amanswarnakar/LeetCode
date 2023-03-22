//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    long long helper(string &s, string r, int x){
        long long int i = 0, ans = 0;
        for(int j = 0; j < s.size(); j++){
            s[i++] = s[j];
            if(i >= 2 and s[i - 2] == r[0] and s[i - 1] == r[1]){
                ans += x; i -= 2;
            }
        }
        s.resize(i);
        return ans;
    }
    long long solve(int x, int y, string s){
      //code here
        int n = s.size();
        string a = "pr", b = "rp";
        if(y > x){
            swap(x, y); swap(a, b);
        }
        return helper(s, a, x) + helper(s, b, y);
    }
};

//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int X,Y;
      cin>>X>>Y;
      string S;
      cin>>S;
      Solution obj;
      long long answer=obj.solve(X,Y,S);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends