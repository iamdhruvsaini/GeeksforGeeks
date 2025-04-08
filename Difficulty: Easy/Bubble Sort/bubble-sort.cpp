//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    // Function to sort the array using bubble sort algorithm.
    void solve(vector<int>& arr,int n){
        //base case
        if(n>arr.size())return ;
        
        //
        for(int i=0;i<arr.size()-n;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        return solve(arr,n+1);
    
    }
    void bubbleSort(vector<int>& arr) {
        // Your code here

        solve(arr,1);
        
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends