//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    int solve(vector<vector<int>> &v, int k){
        int n = v.size(), cnt = 0, flag = 0;
        for(int i = 0; i < n; i++){
            int diff = v[i][1] - v[i][0] + 1;
            if(cnt + diff < k){
                cnt += diff;
            } else {
                int temp = cnt;
                cnt = v[i][0] - 1 + k - temp;
                flag = 1;
                break;
            }
        }
        return flag ? cnt : -1;
    }
    
    vector<int>kthSmallestNum(int n, vector<vector<int>> &range, int q, vector<int> &queries){
        //Write your code here
        sort(range.begin(), range.end());
        vector<vector<int>> v;
        vector<int> ans, temp = range[0];
        for(int i = 1; i < n; i++){
            if(range[i][0] > temp[1]){
                v.emplace_back(temp);
                temp = range[i];
            } else {
                temp[1] = max(temp[1], range[i][1]);
                temp[0] = min(temp[0], range[i][0]);
            }
        }
        v.emplace_back(temp);
        for(auto &i: queries){
            ans.emplace_back(solve(v, i));
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
	    int n;
	    cin >> n;
	    vector<vector<int>>range(n, vector<int>(2, 0));
	    for(int i = 0 ; i < n; i++){
	        cin >> range[i][0] >> range[i][1];
	    }
	    int q;
	    cin >> q;
	    vector<int>queries;
	    for(int i = 0 ; i < q; i++){
	        int x;
            cin >> x;
	        queries.push_back(x);
	    }
	    Solution ob;
	    vector<int>ans = ob.kthSmallestNum(n, range, q, queries);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout << endl;
	}
	return 0;
}

// } Driver Code Ends