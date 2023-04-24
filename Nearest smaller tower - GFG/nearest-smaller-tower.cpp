//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> v){
        // code here
        stack<int> st;
        int n = v.size();
        vector<int> ans(n, -1);
        for(int i = n - 1; i >= 0; i--){
            while(!st.empty() and v[st.top()] >= v[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i = 0; i < n; i++){
            while(!st.empty() and v[st.top()] >= v[i]) st.pop();
            if(!st.empty()){
                if(ans[i] == -1) ans[i] = st.top();
                else {
                    int idx = st.top();
                    if(i - idx < ans[i] - i) ans[i] = idx;
                    if(i - idx == ans[i] - i){
                        if(v[idx] <= v[ans[i]]) ans[i] = idx;
                    }
                }
            }
            st.push(i);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends