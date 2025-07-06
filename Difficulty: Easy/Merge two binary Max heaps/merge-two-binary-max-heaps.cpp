// User function Template for C++

class Solution {
  public:
    void heapify(vector<int>&temp,int i, int value ){
        //max heap
        int index=i;
        int left=2*index+1;
        int right=2*index+2;
        
        if(left<temp.size() && temp[left]>temp[index]){
            index=left;
        }
        if(right<temp.size() && temp[right]>temp[index]){
            index=right;
        }
        
        if(index!=i){
            swap(temp[index],temp[i]);
            heapify(temp,index,value);
        }
        
        return;
    }
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
       // make a common vector
       vector<int>temp;
       for(auto i:a){
           temp.push_back(i);
       }
       for(auto i:b){
           temp.push_back(i);
       }
       
       
       
       // now create a heap from this error as n/2->n are leaf already heap
       
       for(int i=(temp.size()/2)-1;i>=0;i--){
           heapify(temp,i,temp[i]);
       }
       return temp;
    }
};