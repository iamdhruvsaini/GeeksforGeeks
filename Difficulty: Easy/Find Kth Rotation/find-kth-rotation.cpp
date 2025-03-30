//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        //find index of minimum element
        int s=0,e=arr.size()-1;
        int index=-1;
        int mini=INT_MAX;
        while(s<=e){
            int mid=s+(e-s)/2;
            // identify sorted part
            if(arr[mid]>=arr[s]){
                //left part is sorted
                if(arr[s]<mini){
                    mini=arr[s];
                    index=s;
                }
                
                //move to unsorted part
                s=mid+1;
            }
            
            else{
                //right part is sorted
                if(arr[mid]<mini){
                    mini=arr[mid];
                    index=mid;
                }
                
                //move to unsorted half
                
                e=mid-1;
                
                
            }
        
            
        }
        
        return index;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        Solution ob;
        int res = ob.findKRotation(arr);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends