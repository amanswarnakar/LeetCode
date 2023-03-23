//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *right;
    Node *left;

    Node(int x) {
        data = x;
        right = NULL;
        left = NULL;
    }
};

Node *insert(Node *tree, int val) {
    Node *temp = NULL;
    if (tree == NULL) return new Node(val);

    if (val < tree->data) {
        tree->left = insert(tree->left, val);
    } else if (val > tree->data) {
        tree->right = insert(tree->right, val);
    }

    return tree;
}


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void helper(Node *node, int target, int a, int b, int &ans, bool found){
        if(!node) return;
        if(node->data == target) found = true;
        if(found){
            b += node->data;
            if(!node->left and !node->right){
                b -= target; 
                ans = max(a - b, ans);
            }
            helper(node->left, target, a, b, ans, found);
            helper(node->right, target, a, b, ans, found);
        } else {
            a += node->data;
            if(target < node->data) helper(node->left, target, a, b, ans, found);
            else helper(node->right, target, a, b, ans, found);
        }
    }
    int maxDifferenceBST(Node *root,int target){
        // Code here
        int a = 0, b = 0, ans = INT_MIN;
        bool found = false;
        helper(root, target, a, b, ans, found);
        if(ans == INT_MIN) return -1;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node *root = NULL;

        int N;
        cin >> N;
        for (int i = 0; i < N; i++) {
            int k;
            cin >> k;
            root = insert(root, k);
        }

        int target;
        cin >> target;
        Solution ob;
        cout << ob.maxDifferenceBST(root, target);
        cout << endl;
    }
}
// } Driver Code Ends