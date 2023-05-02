//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    int maxSweetness(vector<int>& v, int n, int k) {
        int l = 1, r = accumulate(v.begin(), v.end(), 0);
        while(l <= r){
            int mid = l + (r - l) / 2, cnt = 0, curr = 0;
            for(auto &i: v){
                curr += i;
                if(curr >= mid){
                    curr = 0;
                    cnt++;
                }
            }
            if(cnt <= k) r = mid - 1;
            else l = mid + 1;
        }
        return r;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends