//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        vector<char> lower, upper;
        string ans = "";
        for(auto &ch: str){
            if(islower(ch)) lower.emplace_back(ch);
            else upper.emplace_back(ch);
        }
        sort(lower.begin(), lower.end());
        sort(upper.begin(), upper.end());
        int c1 = 0, c2 = 0;
        for(auto &ch: str){
            if(isupper(ch)) ans += upper[c1++];
            else ans += lower[c2++];
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
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends