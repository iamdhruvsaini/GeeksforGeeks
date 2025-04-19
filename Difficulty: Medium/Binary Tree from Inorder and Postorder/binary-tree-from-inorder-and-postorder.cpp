//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL)
        return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}


// } Driver Code Ends

/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

class Solution {
  public:

    // Function to return a tree created from postorder and inoreder traversals.
    Node * solve(vector<int> &inorder, vector<int> &postorder,int &index,int s,int e,unordered_map<int,int>& mapping){
        if(index < 0 || s>e)return NULL;
        
        // POSTORDER LRN
        Node * temp=new Node(postorder[index]);
        int pos=mapping[postorder[index--]];
        
        temp->right=solve(inorder,postorder,index,pos+1,e,mapping);
        temp->left=solve(inorder,postorder,index,s,pos-1,mapping);
        
        return temp;
    }
    
    Node* buildTree(vector<int> inorder, vector<int> postorder) {
        // code here
        int n=inorder.size();
        
        unordered_map<int,int>mapping;
        for(int i=0;i<inorder.size();i++){
            mapping[inorder[i]]=i;
        }
        
        int index=postorder.size()-1;
        
        return solve(inorder,postorder,index,0,n-1,mapping);
    }
};



//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);

        stringstream ss(input);
        vector<int> inorder;
        int number;
        while (ss >> number) {
            inorder.push_back(number);
        }

        getline(cin, input);
        stringstream ss2(input);
        vector<int> postorder;
        while (ss2 >> number) {
            postorder.push_back(number);
        }
        Solution obj;
        Node* root = obj.buildTree(inorder, postorder);
        preOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends