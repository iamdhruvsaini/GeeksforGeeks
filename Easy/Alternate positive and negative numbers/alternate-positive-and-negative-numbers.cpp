//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    vector<int>temp;
	    int cnt=0;
	    for(int i=0;i<n;i++){
	        if(arr[i]>=0){
	            temp.push_back(arr[i]);
	            cnt++;
	        }
	    }
	    for(int i=0;i<n;i++){
	        if(arr[i]<0){
	            temp.push_back(arr[i]);
	       }
	    }
	    int i=0;
	    int j=cnt;
	    int k=0;
	    while(i<cnt && j<n && k<n){
	        arr[k]=temp[i++];
	        k++;
	        arr[k]=temp[j++];
	        k++;
	    }
	    while(i<cnt){
	        arr[k++]=temp[i++];
	    }
	    while(j<n){
	        arr[k++]=temp[j++];
	    }
	    
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends