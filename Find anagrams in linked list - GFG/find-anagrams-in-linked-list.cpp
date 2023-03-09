//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    char data;
    struct Node *next;

    Node(char x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

struct Node *inputList() {
    int n; // length of link list
    scanf("%d ", &n);

    char data;
    cin >> data;
    struct Node *head = new Node(data);
    struct Node *tail = head;
    for (int i = 0; i < n - 1; ++i) {
        cin >> data;
        tail->next = new Node(data);
        tail = tail->next;
    }
    return head;
}


// } Driver Code Ends
/*

Definition for singly Link List Node
struct Node
{
    char data;
    Node* next;
    Node(int x) {  data = x;  next = NULL; }
};

You can also use the following for printing the link list.
printList(Node* node);
*/

class Solution {
  public:
    vector<Node*> findAnagrams(struct Node* head, string s) {
        vector<Node *> ans;
        Node *start = head, *curr, *end = head;
        int n = s.size();
        map<char, int> mp1, mp2;
        for(auto &i: s) mp2[i]++;
        int cnt1 = 0, cnt2 = mp2.size();
        while(end){
            mp1[end->data]++;
            if(mp1[end->data] == mp2[end->data]) cnt1++;
            while(mp1[end->data] > mp2[end->data]) {
                if(mp1[start->data] == mp2[start->data]) cnt1--;
                mp1[start->data]--;
                start = start->next;
            }
            if(cnt1 == cnt2){
                ans.push_back(start);
                curr = end->next;
                end->next = NULL;
                start = curr;
                end = curr;
                mp1.clear();
                cnt1 = 0;
            } else {
                end = end->next;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        struct Node *head = inputList();

        string s;
        cin >> s;

        Solution obj;
        vector<Node *> res = obj.findAnagrams(head, s);

        for (int i = 0; i < res.size(); i++) {
            printList(res[i]);
        }

        if (res.size() == 0) cout << "-1\n";
    }
}

// } Driver Code Ends