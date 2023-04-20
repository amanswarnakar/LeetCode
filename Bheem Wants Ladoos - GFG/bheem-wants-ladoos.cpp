//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/



class Solution{
public:
    Node* start = NULL ;
    void target(Node* root , int home )
    {
        if(root==NULL)
        return; 
        
        if(root->data==home){
            start=root ;
            return; 
        } 
        
        target(root->left, home ); 
        target(root->right, home ); 
    }
    
    
    int ladoos(Node* root, int home, int k)
    {
        // Your code goes here
        
        target(root, home ); 
        
        if(start==NULL)
        return 0 ; 
        
        map<int ,vector<int>>adj ; 
        queue<Node* >q; 
        q.push(root) ;
        
        while(!q.empty())
        {
            int len= q.size() ;
            while(len--)
            {
                Node* temp= q.front();
                q.pop() ;
                if(temp->left){
                    adj[temp->data].push_back(temp->left->data);
                    adj[temp->left->data].push_back(temp->data);
                    q.push(temp->left);
                }
                if(temp->right){
                    adj[temp->data].push_back(temp->right->data);
                    adj[temp->right->data].push_back(temp->data);
                    q.push(temp->right);
                }
            }
        }
        map<int, int >vis; 
        queue<int>q1; 
        int ans = 0 ; 
        q1.push(start->data) ;
        vis[start->data]=1; 
        while(!q1.empty())
        {
            int len = q1.size() ;
            while(len--)
            {
                int ptr =q1.front() ; 
                q1.pop() ;
                ans+=ptr; 
                for(auto it: adj[ptr])
                {
                    if(!vis[it])
                    {
                        vis[it]=1; 
                        q1.push(it); 
                    }
                }
            }
            k-- ;
            if(k==-1)
            break ;
        }
      return ans ;  
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int home,k;
        cin>> home >> k;
        getchar();
        Solution obj;
        cout<< obj.ladoos(root,home,k) << endl;
    }
	return 0;
}


// } Driver Code Ends