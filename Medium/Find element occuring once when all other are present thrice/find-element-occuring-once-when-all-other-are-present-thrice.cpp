//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int singleElement(int arr[] ,int n) {
        // code here
        sort(arr,arr+n);
        int cnt=1;
        for(int i=0;i<n-1;i++){
            if(arr[i]==arr[i+1])cnt++;
            else{
                if(cnt<3)return arr[i];
                else cnt=1;
            }
        }
        if(cnt==1)return arr[n-1];
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.singleElement(arr,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends