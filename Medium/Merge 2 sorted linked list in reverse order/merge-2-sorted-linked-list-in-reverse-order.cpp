//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
};

void print(struct Node *Node)
{
    while (Node!=NULL)
    {
        cout << Node->data << " ";
        Node = Node->next;
    }
}


Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}


// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
};

*/
class Solution
{
    public:
    Node * reverse(Node *node1){
        Node * prev=NULL;
        Node * curr=node1;
        Node * next=NULL;
        
        while(curr!=NULL){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    struct Node * mergeResult(Node *node1,Node *node2)
    {
        Node * head=NULL;
        Node * tail=NULL;
        Node * temp1=reverse(node1);
        Node * temp2=reverse(node2);
        if(temp1==NULL)return temp2;
        else if(temp2==NULL)return temp1;
        else if(temp1->data > temp2->data){
                head=temp1;
                tail=temp1;
                temp1=temp1->next;
        }
        else{
            head=temp2;
            tail=temp2;
            temp2=temp2->next;
        }
        
        while(temp1!=NULL && temp2!=NULL){
            if(temp1->data > temp2->data){
                tail->next=temp1;
                tail=temp1;
                temp1=temp1->next;
            }
            else{
                tail->next=temp2;
                tail=temp2;
                temp2=temp2->next;
            }
            
        }
        while(temp1!=NULL){
            tail->next=temp1;
            tail=temp1;
            temp1=temp1->next;
            
        }
        while(temp2!=NULL){
            tail->next=temp2;
            tail=temp2;
            temp2=temp2->next;
        }
        
        return head;
    }  
};


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int nA;
        cin>>nA;
        int nB;
        cin>>nB;

        struct Node* headA=NULL;
        struct Node* tempA = headA;

        for(int i=0;i<nA;i++)
        {
            int ele;
            cin>>ele;
            if(headA==NULL)
            {
                headA=tempA=newNode(ele);

            }else{
                tempA->next = newNode(ele);
				tempA=tempA->next;
            }
        }

        struct Node* headB=NULL;
        struct Node* tempB = headB;


        for(int i=0;i<nB;i++)
        {
            int ele;
            cin>>ele;
            if(headB==NULL)
            {
                headB=tempB=newNode(ele);

            }else{
                tempB->next = newNode(ele);
				tempB=tempB->next;
            }
        }
        
        Solution ob;
        struct Node* result = ob.mergeResult(headA,headB);

        print(result);
        cout<<endl;


    }
}

// } Driver Code Ends