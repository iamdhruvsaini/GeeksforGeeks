//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int i=0;
        int j=0;
        int sum=0;
        int prefix[n+1];
        for(int i=1;i<=n;i++){
            prefix[i]=prefix[i-1]+arr[i-1];
        }
        sort(prefix,prefix+n+1);
        
        for(int i=0;i<=n-1;i++){
            if(prefix[i]==prefix[i+1])return true;
        }
        if(prefix[n-1]==prefix[n])return true;
        return false;
        
        
        
        
        
        
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends