//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isStraightHand(int n, int k, vector<int> &v) {
        // code here
        if(n % k > 0) return false;
        map<int, int> mp;
        for(auto &i: v) mp[i]++;
        while(!mp.empty()){
            int a = mp.begin()->first;
            for(int i = 0; i < k; i++){
                if(mp[a + i] == 0) return false;
                else if(--mp[a + i] == 0) mp.erase(a + i);
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, groupSize;
        cin >> N >> groupSize;

        vector<int> hand(N);
        for (int i = 0; i < N; i++) cin >> hand[i];

        Solution obj;
        int ans = obj.isStraightHand(N, groupSize, hand);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends