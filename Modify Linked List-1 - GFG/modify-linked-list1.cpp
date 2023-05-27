//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node *reverse(struct Node *node){
        Node *pre = NULL, *cur = node, *nex;
        while(cur){
            nex = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nex;
        }
        return pre;
    }
    struct Node* modifyTheList(struct Node *head)
    {
        //add code here.
        Node *dh = new Node(0);
        dh->next = head;
        vector<int> v;
        Node *fast = dh->next, *slow = dh->next;
        while(fast and fast->next){
            v.emplace_back(slow->data);
            fast = fast->next->next;
            slow = slow->next;
        }
        dh->next = reverse(head);
        fast = dh->next;
        
        int i = 0;
        while(i < v.size()){
            fast->data = fast->data - v[i++];
            fast = fast->next;
        }
        return dh->next;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends