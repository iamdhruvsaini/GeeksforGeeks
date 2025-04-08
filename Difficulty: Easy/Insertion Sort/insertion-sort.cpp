//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Please change the array in-place
    void solve(vector<int>& arr,int n){
        if(n>=arr.size())return;
        
        int element=arr[n];
        int j=n-1;
        for(;j>=0;j--){
            if(arr[j]>=element){
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1]=element;
        
        
        solve(arr,n+1);
    }
    void insertionSort(vector<int>& arr) {
        // code here
        solve(arr,1);
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
        obj.insertionSort(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends