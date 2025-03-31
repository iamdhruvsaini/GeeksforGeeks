//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        // Your code goes here
        if(n==1)return 1;
        int s=1 ,e=n-1,validAns=1;
        while(s<=e){
            //
            int mid=s+(e-s)/2;
            
            int square=mid*mid;
            if(square==n){
                return mid;
            }
            else if(square>n){
                e=mid-1;
            }
            else{
                validAns=mid;
                s=mid+1;
            }
        }
        return validAns;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends