//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int m, int n){
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pair<int, int> ans;
        int i = 0, j = 0, k = 0;
        while(min(i, j) >= 0 and i < m and j < n){
            ans = {i, j};
            if(matrix[i][j] == 1){
                matrix[i][j] = 0;
                k = (k + 1) % 4;
            }
            i += dir[k].first;
            j += dir[k].second;
        }
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    int tc;
	scanf("%d", &tc);
	while(tc--){
		int row, col;
		scanf("%d", &row);
		scanf("%d", &col);
		vector<vector<int>> matrix(row , vector<int> (col));
	 
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++){
			    cin>>matrix[i][j];
			}
		}
		Solution obj;
		pair<int,int> p = obj.endPoints(matrix, row, col);
		
		cout << "(" << p.first << ", " << p.second << ")" << endl;
	}
	return 0;
}
// } Driver Code Ends