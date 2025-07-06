// Structure of node
/*class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution {
  public:
  
    bool checkCBT(Node * node,int index,int totalNodes){
        if(node==NULL)return 1;
        
        if(index>=totalNodes)return 0;
        else{
            
        bool left=checkCBT(node->left,2*index+1,totalNodes);
        bool right=checkCBT(node->right,2*index+2,totalNodes);
        return left && right;
        
        }
    }
    
    
    int countNodes(Node * node){
        if(node==NULL){
            return 0;
        }
        int left=countNodes(node->left);
        int right=countNodes(node->right);
        int cnt=left+right+1;
    
        return cnt;
    }
    
    
    bool checkHeap(Node * node){
        // check for leaf node
        if(node->left==NULL && node->right==NULL)return 1;
        
        // check if right is NULL
        if(node->right==NULL){
            return node->data >= node->left->data;
        }
        
        // check for if both left and right are not null
        
        bool left=checkHeap(node->left);
        bool right=checkHeap(node->right);
        
        if(left && right && node->data >= node->left->data && node->data >= node->right->data){
            return 1;
        }
        return 0;
        
    }
    
    bool isHeap(Node* node) {
        // code here
        int totalNodes=countNodes(node);
        if(checkCBT(node,0,totalNodes) && checkHeap(node)){
            return 1;
        }
        
        return 0;
    }
};