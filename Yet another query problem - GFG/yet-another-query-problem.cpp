//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &v, vector<vector<int>> &q) {
        // code here
        vector<int> ans;
        map<int, int> mp;
        for(int i = n - 1; i >= 0; i--){
            mp[v[i]]++;
            v[i] = mp[v[i]];
        }
        // for(auto i: v) cout<<i<<" -> ";
        // cout<<endl;
        for(auto &i: q){
            int l = i[0], r = i[1], k = i[2], cnt = 0;
            for(int j = l; j <= r; j++){
                if(v[j] == k) cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends