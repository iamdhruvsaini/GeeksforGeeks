//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here.
        if(n==1)return m;
        if(m==1)return 1;
        int s=1,e=m-1;
        
        while(s<=e){
            int mid=s+(e-s)/2;
            
            int value=pow(mid,n);
            if(value==m){
                return mid;
            }
            else if(value>m){
                e=mid-1;
            }
            else{
                s=mid+1;
            }
        }
        return -1;
        
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        Solution ob;
        int ans = ob.nthRoot(n, m);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends