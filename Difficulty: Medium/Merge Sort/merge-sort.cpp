//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void merge(vector<int>& arr, int s, int e,int mid){

        int len1=mid-s+1;
        int len2=e-mid;
        vector<int>arr1;
        vector<int>arr2;
        for(int i=s;i<=mid;i++){
            arr1.push_back(arr[i]);
        }
        for(int i=mid+1;i<=e;i++){
            arr2.push_back(arr[i]);
        }
        
        //now mwege in sorted manner
        int i=0,j=0;
        int k=s;
        while(i<len1 && j<len2){
            if(arr1[i]<=arr2[j]){
                arr[k++]=arr1[i++];
            }
            else{
                arr[k++]=arr2[j++];
            }
        }
        while(i<len1){
            arr[k++]=arr1[i++];
        }
        while(j<len2){
            arr[k++]=arr2[j++];
        }
        
        
    }
    void mergeSort(vector<int>& arr, int l, int r) {
        // code here
        if(l>=r)return;
        int mid=l+(r-l)/2;
        
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,r,mid);
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        obj.mergeSort(arr, 0, arr.size() - 1);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends