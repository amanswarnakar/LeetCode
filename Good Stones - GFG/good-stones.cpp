//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    int goodStones(int n,vector<int> &arr){
        // Code here
        vector<bool> vis(n, false);
        set<int> st;
        vector<int> temp;
        for(int i = 0; i < n; i++){
            if(vis[i]) continue;
            int j = i;
            while(!vis[j]){
                vis[j] = true;
                temp.push_back(j);
                j += arr[j];
                if(j >= n or j < 0){
                    for(auto &i: temp){
                        st.insert(i);
                    }
                    temp.clear();
                    break;
                }
            }
            if(temp.size() and st.count(j)){
                for(auto &i: temp){
                    st.insert(i);
                }
            }
            temp.clear();
        }
        return st.size();
    }  
};

//{ Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.goodStones(n,arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends