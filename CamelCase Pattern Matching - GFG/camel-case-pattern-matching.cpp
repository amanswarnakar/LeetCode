//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    string helper(string s){
        string res = "";
        for(auto &i: s){
            if(isupper(i)) res += i;
        }
        return res;
    }
    vector<string> CamelCase(int n, vector<string> dict, string p) {
        // code here
        vector<string> ans;
        sort(dict.begin(), dict.end());
        vector<string> vs;
        for(auto &i: dict){
            vs.emplace_back(helper(i));
        }
        for(int i = 0; i < n; i++){
            int j;
            for(j = 0; j < p.size(); j++){
                if(vs[i][j] != p[j]) break;
            }
            if(j == p.size()) ans.emplace_back(dict[i]);
        }
        vector<string> temp = {"-1"};
        return ans.size() ? ans : temp;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends