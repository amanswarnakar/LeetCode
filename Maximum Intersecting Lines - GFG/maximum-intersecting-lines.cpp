//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int n) {
        // Code here
        vector<pair<int, bool>> v;
        for(auto &i: lines){
            v.emplace_back(make_pair(i[0], false));
            v.emplace_back(make_pair(i[1], true));
        }
        sort(v.begin(), v.end());
        int ans = 0, cnt = 0;
        for(auto &i: v){
            if(i.second) cnt--;
            else cnt++;
            ans = max(ans, cnt);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(2));
        for (int j = 0; j < 2; j++) {
            for (int i = 0; i < N; i++) {
                cin >> mat[i][j];
            }
        }
        Solution obj;
        cout << obj.maxIntersections(mat, N) << endl;
    }
}
// } Driver Code Ends