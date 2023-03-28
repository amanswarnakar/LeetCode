//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

class Shop
{
    vector<int> chocolates;
    int countOfCalls;
    public:
    Shop()
    {
        countOfCalls = 0;
    }
    void addChocolate(int x)
    {
        chocolates.push_back(x);
    }
    long long get(int i)
    {
        countOfCalls++;
        if(i<0 || i>=(int)chocolates.size() || countOfCalls>50)return -1;
        return chocolates[i];
    }
};


// } Driver Code Ends
//User function Template for Java

/*
Instructions - 

    1. 'shop' is object of class Shop.
    2. User 'shop.get(int i)' to enquire about the price
            of the i^th chocolate.
    3. Every chocolate in shop is arranged in increasing order
            i.e. shop.get(i) <= shop.get(i + 1) for all 0 <= i < n - 1
*/
class Solution{
    public:
    Shop shop;
    Solution(Shop s)
    {
        this->shop = s;
    }
    long long find(int n, long k){
        // Return the number of chocolates Geek had
        // enjoyed out of 'n' chocolates availabe in the
        // 'shop'.
        Shop s = this->shop;
        unordered_map<int, long long> um;
        int l = 0, r = n - 1, ans = 0;
        while(true){
            int idx = -1;
            long long temp;
            while(l <= r){
                int mid = l + (r - l) / 2;
                if(!um.count(mid)){
                    temp = s.get(mid);
                    um[mid] = temp;
                } else temp = um[mid];
                if(temp == -1) return ans;
                if(temp <= k){
                    idx = mid;
                    l = mid + 1;
                } else r = mid - 1; 
            }
            if(idx != -1){
                if(!um.count(idx)){
                    temp = s.get(idx);
                    um[idx] = temp;
                } else temp = um[idx];
                if(temp == -1) return ans;
                ans += k / temp;
                k %= temp;
            } else return ans;
            l = 0; r = idx - 1;
        }
        return ans;
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        long long k;
        cin >> k;
        
        Shop shop;
        for(int i = 0; i<n; i++)
        {
            int x;
            cin >> x;
            shop.addChocolate(x);
        }
        
        Solution obj(shop);
        long long res = obj.find(n, k);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends