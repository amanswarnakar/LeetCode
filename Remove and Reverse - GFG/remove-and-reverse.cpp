//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
  public:
    string removeReverse(string s) {
        // code here
        int n = s.size(), l = 0, r = n - 1;
        unordered_map<char, int> um;
        for(auto &i: s) um[i]++;
        bool flag = true;
        while(l <= r){
            if(flag){
                if(um[s[l]] > 1){
                    um[s[l]]--;
                    s[l] = '0';
                    flag = false;
                }
                l++;
            } else {
                if(um[s[r]] > 1){
                    um[s[r]]--;
                    s[r] = '0';
                    flag = true;
                }
                r--;
            }
        }
        string ans = "";
        for(auto &i: s){
            if(i != '0') ans += i;
        }
        if(flag) return ans;
        reverse(begin(ans), end(ans));
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin>>S;
        Solution obj;
        auto ans = obj.removeReverse(S);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends